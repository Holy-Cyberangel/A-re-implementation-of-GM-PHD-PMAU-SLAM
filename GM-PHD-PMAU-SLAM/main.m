% 主程序
% monte carlo simulation->toki simulation->filter
clear all;
addpath("./tools");
addpath("./data");
run("set_params.m");
load("./data/Configration.mat");
run("data_generate.m");
load("./data/Measurement.mat","Measurement","Odometry","range","M");
load("./data/Environment_SLAM.mat","Robot_Control","T",'T_total',"Robot_Groundtruth","Landmark_Groundtruth");
% Monte Carlo settings

nTrials = params.monte_carlo;
pos_rmse_trials = nan(1,nTrials);
yaw_rmse_trials = nan(1,nTrials);
gospa_trials = nan(1,nTrials);
runtime = nan(1,nTrials);
map_components_trials = nan(1,nTrials);
% monte carlo simulation
delete(gcp('nocreate'));
parpool('local', 3);
parfor m=1:nTrials
% for m=1:nTrials
    % Initiatem
    x = zeros(3,T_total);  
    x(:,1) = Robot_Groundtruth(:,1);
    % P = 1*eye(3);
    P = 10000*diag([0.001,0.001,0.0001*pi/180]).^2;
    % P = diag([1,1,1*pi/180]).^2;
    % 初始化地图
    map = struct();
    cur_mea = Measurement{m,1};
    mea_dxdy = preprocess(cur_mea,params);
    for i = 1:size(mea_dxdy,2)
        map(i).m = x(1:2,1)+rotate_x2w(-x(3,1))*mea_dxdy(:,i);
        map(i).w = params.birth_intensity;
        map(i).P = eye(2);
    end
    tic;
    for k=2:T_total
        [x_,P_] = pose_predict(x(:,k-1),P,Odometry{m,k-1},T,params.Qu);   % 使用解析方法
        cur_mea = Measurement{m,k};
        % 转换量测的表示，方便后续线性计算,局部坐标系的dxdy
        % 如果转到世界坐标系需要加上位姿和旋转矩阵
        [mea_dxdy,R] = preprocess(cur_mea,params);
        P_prev = P_;
        % 迭代更新
        for i = 1:params.iter_max
            x0 = x_;
            fov_idx = map_predict(x_,map,params);
            [x_,P_] = pose_update(x_,x0,P_prev,map(fov_idx),mea_dxdy,params,2,R,i);
            % if norm(x0-x_) < params.epsilon
            %     break;
            % end
        end
        x(:,k) = x_;
        P = regularize_cov(P_);
        % % 地图预测(获取fov内的地标索引）
        % fov_idx = map_predict(x_,map,params);
        % % 位姿更新（CI1目前还有bug|矩2）
        % [x(:,k),P] = pose_update(x_,P_prev,map(fov_idx),mea_dxdy,params,2);
        % 重新获取地图内可见地标
        fov_idx = map_predict(x(:,k),map,params);
        % 地图PHD更新
        [map,birth_idx] = map_update(x(:,k),P,map(~fov_idx),map(fov_idx),mea_dxdy,params,R);
        % map合并剪枝
        map = tuning(map,params);
        % 新生策略（最后一个时间步可以不需要新生）
        if k~=T_total
            map = birth(x(:,k),P,map, mea_dxdy(:,birth_idx),params,R(1,birth_idx));
        end
        % disp(size(map,2));
    end
    % 使用compute_metrics计算本次试验的指标
    [pos_rmse, yaw_rmse, gospa_val, map_count] = compute_metrics(x, map, Robot_Groundtruth, Landmark_Groundtruth, params);
    pos_rmse_trials(m) = pos_rmse;
    yaw_rmse_trials(m) = rad2deg(yaw_rmse);
    gospa_trials(m) = gospa_val;
    runtime(m) = toc/4000;
    map_components_trials(m) = map_count;
    fprintf('  trial %d: map=%d posRMSE=%.4f yawRMSE=%.4fdeg gospa=%.4f runtime=%.4fs\n', m, map_count, pos_rmse, rad2deg(yaw_rmse), gospa_val, runtime(m));
end
save("./data/result.mat","pos_rmse_trials","yaw_rmse_trials","gospa_trials","runtime");