function [d, loc_err, miss_err, false_err] = gospa(est, truth, p, c)
% GOSPA metric between estimated landmarks and ground-truth
% est: N x 2, truth: M x 2
% p: order (usually 2), c: cutoff distance
% 返回值: d (总误差), 以及分解后的三项误差

if isempty(est) && isempty(truth)
    d = 0; loc_err = 0; miss_err = 0; false_err = 0;
    return;
end

n = size(est,1);
m = size(truth,1);

% 处理一方为空的特殊情况
if n == 0
    miss_err = (m * (c^p) / 2); % GOSPA 标准定义中，数量误差通常除以 2
    false_err = 0;
    loc_err = 0;
    d = (miss_err + false_err + loc_err)^(1/p);
    return;
end
if m == 0
    miss_err = 0;
    false_err = (n * (c^p) / 2);
    loc_err = 0;
    d = (miss_err + false_err + loc_err)^(1/p);
    return;
end

% 1. 计算距离代价矩阵 (使用 pdist2 效率更高)
% C(i,j) = min(c, dist(est_i, truth_j))^p
C = min(c, pdist2(est, truth)).^p;

% 2. 执行最优分配 (寻找最小化总距离的点对)
if exist('matchpairs','file')
    % matchpairs 在这里寻找最小权重匹配
    % 阈值设为 c^p，超过此值的匹配被视为无效
    pairs = matchpairs(C, c^p);
else
    % 备选方案：简单的贪心匹配
    pairs = [];
    C_copy = C;
    while true
        [min_v, idx] = min(C_copy(:));
        if min_v >= c^p || isinf(min_v), break; end
        [ii, jj] = ind2sub(size(C_copy), idx);
        pairs = [pairs; ii, jj]; %#ok<AGROW>
        C_copy(ii, :) = inf;
        C_copy(:, jj) = inf;
    end
end

% 3. 计算三个分解项
num_matches = size(pairs, 1);

% (1) 定位误差: 成功匹配的点对之间的距离之和
if num_matches > 0
    idx = sub2ind(size(C), pairs(:,1), pairs(:,2));
    loc_err = sum(C(idx));
else
    loc_err = 0;
end

% (2) 漏检误差 (Missed targets): 没被匹配上的真值
miss_err = (m - num_matches) * (c^p / 2);

% (3) 虚警误差 (False estimates): 没被匹配上的估计值
false_err = (n - num_matches) * (c^p / 2);

% 4. 计算总 GOSPA 距离
% 公式: d = (loc_err + miss_err + false_err)^(1/p)
d = (loc_err + miss_err + false_err)^(1/p);

end