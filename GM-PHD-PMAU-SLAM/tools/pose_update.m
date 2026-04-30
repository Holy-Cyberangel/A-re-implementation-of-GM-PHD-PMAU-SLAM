function [x,P] = pose_update(x_,x0,P_,map,Z,params,model,R,iter_cnt)
    PHD_matrix(size(map,2),size(Z,2)+1) = struct();
    sum_w = 0;
    PD = params.P_D;
    if  size(map,2) == 0
        x = x_;
        P = P_;
        return;
    end
    num_map = size(map,2);
    num_Z = size(Z,2);
    for i = 1:num_map
        PHD_matrix(i,1).x = x_;
        % if iter_cnt == params.iter_max
            PHD_matrix(i,1).P = P_;
        % end
        PHD_matrix(i,1).w = map(i).w*(1-PD);
    end
    sum_map = params.clutter_rate * ones(1,num_Z+1);
    for j = 2:num_Z+1
        m = j-1;
        for i = 1:num_map
            theta = x_(3);
            dx = map(i).m(1) - x_(1);
            dy = map(i).m(2) - x_(2);
            Z_ = rotate_x2w(theta) * [dx; dy];
            H = [-cos(theta), -sin(theta),  -dx*sin(theta) + dy*cos(theta);
                 sin(theta), -cos(theta), -dx*cos(theta) - dy*sin(theta)];
            Hm = [ cos(theta),  sin(theta);
                -sin(theta),  cos(theta)];
            S = H*P_*H'+R{m} + Hm*map(i).P*Hm';
            K = (P_*H')/S;
            % K = (P_*H')/(H*P_*H'+R{m});
            nu = Z(:,m)-Z_;
            % PHD_matrix(i,j).x = x0+K*(nu-H*(x0-x_));
            PHD_matrix(i,j).x = x_+K*nu;
            % if iter_cnt == params.iter_max
                PHD_matrix(i,j).P = (eye(3)-K*H)*P_;
            % end
            % PHD_matrix(i,j).w = Likelihood(Z_,Z(:,m),H*P_*H'+R{m})*PD*map(i).w;
            PHD_matrix(i,j).w = Likelihood(Z_,Z(:,m),S)*PD*map(i).w;
            % sum_map(i) = sum_map(i) + PHD_matrix(i,j).w;
            sum_map(j) = sum_map(j) + PHD_matrix(i,j).w;
        end
    end

    for i = 1:num_map
        for j = 2:num_Z+1
            PHD_matrix(i,j).w = PHD_matrix(i,j).w / sum_map(j);
            if PHD_matrix(i,j).w > params.PHD_det_keep
                sum_w = sum_w + PHD_matrix(i,j).w;
            else
                PHD_matrix(i,j).w = 0;
            end
        end
    end
    for i = 1:size(map,2)
        if PHD_matrix(i,1).w > params.PHD_miss_keep
            sum_w = sum_w+PHD_matrix(i,1).w;
        else
            PHD_matrix(i,1).w = 0;
        end
    end

    
    if model == 1
        % CI-fusion
        inv_P = zeros(3,3);
        x_info = zeros(3,1);
        
        omega_sum = 0;
        
        for i = 1:size(map,2)
            for j = 1:size(Z,2)+1
                
                % 归一化PHD权重（只用于筛选）
                w = PHD_matrix(i,j).w / sum_w;
                
                % 协方差正则化
                P_ij = regularize_cov(PHD_matrix(i,j).P);
                x_ij = PHD_matrix(i,j).x;
                
                % ---------- 关键修改 ----------
                % CI权重（基于信息量）
                info_weight = 1 / trace(P_ij);
                
                % 可选：结合PHD权重（推荐）
                omega = w * info_weight;
                
                omega_sum = omega_sum + omega;
                
                inv_P = inv_P + omega * inv(P_ij);
                x_info = x_info + omega * inv(P_ij) * x_ij;
            end
        end
        
        % 归一化
        inv_P = inv_P / omega_sum;
        x_info = x_info / omega_sum;
        
        % 求最终结果
        inv_P = regularize_cov(inv_P);
        P = inv(inv_P);
        x = P * x_info;
    elseif model == 2
        % 矩匹配
        P = zeros(3,3);
        x = zeros(3,1);
        for i = 1:size(map,2)
            for j = 1:size(Z,2)+1
                PHD_matrix(i,j).w = PHD_matrix(i,j).w/sum_w;
                x = x+PHD_matrix(i,j).w*PHD_matrix(i,j).x;
            end
        end
        % calculate P
        if iter_cnt == params.iter_max
            for i = 1:size(map,2)
                for j = 1:size(Z,2)+1
                    P = P+PHD_matrix(i,j).w*(PHD_matrix(i,j).P+(PHD_matrix(i,j).x-x)*(PHD_matrix(i,j).x-x)');
                end
            end
            P = regularize_cov(P);
        end
    end
end