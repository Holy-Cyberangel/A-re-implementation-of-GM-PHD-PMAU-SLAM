% Main script: Monte Carlo simulation -> filtering -> metrics
clear all;
addpath("./tools");
addpath("./data");
run("set_params.m");
load("./data/Configration.mat");
run("data_generate.m");
load("./data/Measurement.mat","Measurement","Odometry","range","M");
load("./data/Environment_SLAM.mat","Robot_Control","T","T_total","Robot_Groundtruth","Landmark_Groundtruth");
% Monte Carlo settings
nTrials = params.monte_carlo;
pos_rmse_trials = nan(1,nTrials);
yaw_rmse_trials = nan(1,nTrials);
gospa_trials = nan(1,nTrials);
runtime = nan(1,nTrials);
map_components_trials = nan(1,nTrials);
% params.R = 3*params.R;

use_mex_core = exist('slam_step_mex','file') == 3;
if use_mex_core
    fprintf('Using slam_step_mex for the core loop.\n');
else
    fprintf('slam_step_mex not found, falling back to MATLAB functions.\n');
end

parfor m = 1:nTrials
% for m = 1:nTrials
    x = zeros(3,T_total);
    x(:,1) = Robot_Groundtruth(:,1);
    P = diag([0.001,0.001,0.0001*pi/180]).^2;

    map = struct();
    cur_mea = Measurement{m,1};
    [mea_dxdy,R] = preprocess(cur_mea,params);
    for i = 1:size(mea_dxdy,2)
        map(i).m = x(1:2,1) + rotate_x2w(-x(3,1)) * mea_dxdy(:,i);
        map(i).w = params.birth_intensity;
        % map(i).P = 0.1*eye(2);
        % 标准协方差传递初始化
        Jx = [1 0 mea_dxdy(1,i) * sin(-x(3,1)) - mea_dxdy(2,i) * cos(-x(3,1)); ...
              0 1 mea_dxdy(1,i) * cos(-x(3,1)) + mea_dxdy(2,i) * sin(-x(3,1))];
        map(i).P = Jx*P*Jx'+rotate_x2w(-x(3,1))*R{i}*rotate_x2w(-x(3,1))';
    end

    tic;
    for k = 2:T_total
        [x(:,k),P,map] = slam_step_mex(x(:,k-1),P,Odometry{m,k-1},Measurement{m,k},map,params,T,k==T_total);
    end
    runtime(m) = toc / T_total;
    [pos_rmse, yaw_rmse, gospa_val, map_count] = compute_metrics(x, map, Robot_Groundtruth, Landmark_Groundtruth, params);
    pos_rmse_trials(m) = pos_rmse;
    yaw_rmse_trials(m) = rad2deg(yaw_rmse);
    gospa_trials(m) = gospa_val;
    map_components_trials(m) = map_count;
    fprintf('  trial %d: map=%d posRMSE=%.4f yawRMSE=%.4fdeg gospa=%.4f runtime=%.4fs\n', m, map_count, pos_rmse, rad2deg(yaw_rmse), gospa_val, runtime(m));
end

save("./data/result.mat","pos_rmse_trials","yaw_rmse_trials","gospa_trials","runtime");