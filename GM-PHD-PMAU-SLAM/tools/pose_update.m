function [x,P] = pose_update(x_,x0,P_,map,Z,params,model,R,iter_cnt)
    PHD_matrix(size(map,2),size(Z,2)+1) = struct();
    sum_w = 0;
    PD = params.P_D;
    if  size(map,2) == 0
        x = x_;
        P = P_;
        return;
    end
    for i = 1:size(map,2)
        theta = x_(3);
        dx = map(i).m(1) - x_(1);
        dy = map(i).m(2) - x_(2);
        Z_ = rotate_x2w(theta) * [dx; dy];
        H = [-cos(theta), -sin(theta),  -dx*sin(theta) + dy*cos(theta);
        sin(theta), -cos(theta), -dx*cos(theta) - dy*sin(theta)];
        sum = params.clutter_rate;
        for j = 1:size(Z,2)+1
            if j==1
                PHD_matrix(i,j).x = x_;
                if iter_cnt == params.iter_max
                    PHD_matrix(i,j).P = P_;
                end
                PHD_matrix(i,j).w = map(i).w*(1-PD);
                % sum = sum+PHD_matrix(i,j).w;
            else
                K = (P_*H')/(H*P_*H'+R{j-1});
                nu = Z(:,j-1)-Z_;
                PHD_matrix(i,j).x = x0+K*(nu-H*(x0-x_));
                if iter_cnt == params.iter_max
                    PHD_matrix(i,j).P = (eye(3)-K*H)*P_;
                end
                PHD_matrix(i,j).w = Likelihood(Z_,Z(:,j-1),H*P_*H'+R{j-1})*PD*map(i).w;
                sum = sum+PHD_matrix(i,j).w;
            end
        end
        for j = 2:size(Z,2)+1
            PHD_matrix(i,j).w = PHD_matrix(i,j).w/sum;
            if PHD_matrix(i,j).w > params.PHD_det_keep
                sum_w = sum_w+PHD_matrix(i,j).w;
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

    % guard against zero total weight
    if sum_w <= eps
        x = x_;
        P = P_;
        return;
    end
    if model == 1
        % CI-fusion(待DEBUG)
        inv_P = zeros(3,3);
        x = zeros(3,1);
        for i = 1:size(map,2)
            for j = 1:size(Z,2)+1
                PHD_matrix(i,j).w = PHD_matrix(i,j).w/sum_w;
                PHD_matrix(i,j).P = regularize_cov(PHD_matrix(i,j).P);
                inv_P = inv_P+PHD_matrix(i,j).w*inv(PHD_matrix(i,j).P);
                x = x+PHD_matrix(i,j).w*inv(PHD_matrix(i,j).P)*PHD_matrix(i,j).x;
            end
        end
        inv_P = regularize_cov(inv_P);
        P = inv(inv_P);
        x = P*x;
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