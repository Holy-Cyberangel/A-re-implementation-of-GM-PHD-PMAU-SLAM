function [map,birth_idx] = map_update(x,P,map,inmap,Z,params,R)
    PD = params.P_D;
    numZ = size(Z,2);
    numIn = size(inmap,2);
    % 预处理量测，简化后续操作Z局部坐标系的dxdy->全局xy
    Zmap = zeros(2,numZ);
    rotate_matrix = rotate_x2w(-x(3));
    for i = 1:size(Z,2)
        Zmap(:,i) = x(1:2)+rotate_matrix*Z(:,i);
        % R{i} = rotate_matrix*R{i}*rotate_matrix';
        Jx = [1 0 Z(1,i)*sin(-x(3))-Z(2,i)*cos(-x(3));
              0 1 Z(1,i)*cos(-x(3))+Z(2,i)*sin(-x(3))];
        R{i} = rotate_matrix*R{i}*rotate_matrix'+Jx*P*Jx';
    end
    if size(inmap,2) == 0
        birth_idx = true(numZ,1);
        return;
    end
    Tmap(numIn,numZ+1) = struct('m',[],'P',[],'w',[]);
    for j = 1:numZ+1
        sum = params.clutter_rate;
        for i = 1:numIn
            if j==1
                Tmap(i,j).m = inmap(i).m;
                Tmap(i,j).P = inmap(i).P;
                Tmap(i,j).w = inmap(i).w*(1-PD);
                %sum = sum+Tmap(i,j).w;
            else
                S = inmap(i).P+R{j-1};
                K = inmap(i).P/S;
                nu = Zmap(:,j-1)-inmap(i).m;
                Tmap(i,j).m = inmap(i).m+K*nu;
                Tmap(i,j).P = (eye(2)-K)*inmap(i).P;
                Tmap(i,j).w = Likelihood(inmap(i).m,Zmap(:,j-1),S)*PD*inmap(i).w;
                sum = sum+Tmap(i,j).w;
            end
        end
        if j~= 1
            for i = 1:numIn
                Tmap(i,j).w = Tmap(i,j).w/sum;
            end
        end
    end

    prune_thresh = params.map_miss_prune_threshold;
    n = size(map,2);
    birth_idx = true(numZ,1);
    if isfield(Tmap, 'm')
        % 先处理每一行的第一列（漏检更新部分）
        for i = 1:size(Tmap,1)
            if Tmap(i,1).w >prune_thresh
                n = n+1;
                map(n).m = Tmap(i,1).m;
                map(n).w = Tmap(i,1).w;
                % map(n).P = Tmap(i,1).P;
                map(n).P = regularize_cov(Tmap(i,1).P);
            end
        end
        % 处理PHD更新部分
        for j = 2:size(Tmap,2)
            for i = 1:size(Tmap,1)
                if Tmap(i,j).w >params.map_detection_add_threshold
                    n = n+1;
                    map(n).m = Tmap(i,j).m;
                    map(n).w = Tmap(i,j).w;
                    % map(n).P = Tmap(i,j).P;
                    map(n).P = regularize_cov(Tmap(i,j).P);
                    birth_idx(j-1) = false;
                end
            end
        end
    end
end




% function [map,birth_idx] = map_update(x,P,map,inmap,Z,params,R)
%     PD = params.P_D;
%     numZ = size(Z,2);
%     numIn = size(inmap,2);
% 
%     % Convert measurements from local to global coordinates
%     Zmap = zeros(2,numZ);
%     for jj = 1:numZ
%         Zmap(:,jj) = x(1:2) + rotate_x2w(-x(3)) * Z(:,jj);
%     end
% 
%     if numIn == 0
%         birth_idx = true(numZ,1);
%         return;
%     end
% 
%     % Compute likelihood contributions L(i,j) = PD * w_i * N(z_j | m_i, P_i+R)
%     L = zeros(numIn, numZ);
%     Ks = cell(numIn, numZ);
%     for i = 1:numIn
%         for j = 1:numZ
%             S = inmap(i).P + R{j};
%             L(i,j) = PD * inmap(i).w * Likelihood(inmap(i).m, Zmap(:,j), S);
%             Ks{i,j} = inmap(i).P / (inmap(i).P + R{j});
%         end
%     end
% 
%     D = params.clutter_rate + sum(L,1); % 1 x numZ
% 
%     % Initialize outputs
%     new_map = map; % keep components outside FOV
%     n = size(new_map,2);
%     birth_idx = true(numZ,1);
%     prune_thresh = params.map_miss_prune_threshold;
% 
%     for i = 1:numIn
%         % missed-detection component
%         w_miss = (1-PD) * inmap(i).w;
%         if w_miss > prune_thresh
%             n = n + 1;
%             new_map(n).m = inmap(i).m;
%             new_map(n).P = regularize_cov(inmap(i).P);
%             new_map(n).w = w_miss;
%         end
%         % detection-updated components
%         for j = 1:numZ
%             if D(j) <= 0
%                 continue;
%             end
%             w = L(i,j) / D(j);
%             if w > params.map_detection_add_threshold
%                 n = n + 1;
%                 K = Ks{i,j};
%                 m_upd = inmap(i).m + K * (Zmap(:,j) - inmap(i).m);
%                 P_upd = (eye(2) - K) * inmap(i).P;
%                 new_map(n).m = m_upd;
%                 new_map(n).P = regularize_cov(P_upd);
%                 new_map(n).w = w;
%                 birth_idx(j) = false;
%             end
%         end
%     end
%     map = new_map;
% end