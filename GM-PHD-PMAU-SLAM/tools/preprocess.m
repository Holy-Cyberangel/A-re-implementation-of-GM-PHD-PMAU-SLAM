function [mea_xy,R] = preprocess(cur_mea,params)
    % mea_xy = zeros(2,size(cur_mea,2));
    % for i = 1:size(mea_xy,2)
    %     mea_xy(1,i) = cur_mea(1,i)*cos(cur_mea(2,i));
    %     mea_xy(2,i) = cur_mea(1,i)*sin(cur_mea(2,i));
    % end
    r = cur_mea(1,:);
    theta = cur_mea(2,:);
    mea_xy = [r .* cos(theta); r .* sin(theta)];
    % 转换噪声协方差
    R = cell(1,size(mea_xy,2));
    for i = 1:size(mea_xy,2)
        J = [cos(theta(i)), -r(i)*sin(theta(i));
             sin(theta(i)), r(i)*cos(theta(i))];
        R{i} = J*params.R*J';
    end
end
