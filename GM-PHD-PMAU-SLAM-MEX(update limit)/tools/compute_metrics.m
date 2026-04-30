function [pos_rmse, yaw_rmse, gospa_val, map_count] = compute_metrics(x, map, Robot_Groundtruth, Landmark_Groundtruth, params)
% COMPUTE_METRICS Compute pose RMSEs and OSPA for a trial
% Usage:
%   [pos_rmse, yaw_rmse, ospa_val, map_count] = compute_metrics(x,map,Robot_Groundtruth,Landmark_Groundtruth,params)
if nargin < 5
    params = struct();
end
T_total = size(x,2);
pos_err = zeros(1,T_total);
yaw_err = zeros(1,T_total);
for kk = 1:T_total
    pos_err(kk) = norm(x(1:2,kk) - Robot_Groundtruth(1:2,kk));
    yaw_tmp = mod(x(3,kk) - Robot_Groundtruth(3,kk) + pi, 2*pi) - pi;
    yaw_err(kk) = yaw_tmp;
end
pos_rmse = sqrt(mean(pos_err.^2));
yaw_rmse = sqrt(mean(yaw_err.^2));

% Prepare ground-truth landmark positions if provided
if nargin < 4 || isempty(Landmark_Groundtruth)
    GTpos = [];
else
    GT = Landmark_Groundtruth;
    if size(GT,2) >= 3
        GTpos = GT(:,2:3);
    else
        GTpos = GT;
    end
end

% Compute OSPA between estimated map and GT landmarks when possible
if isfield(map,'m') && ~isempty(map) && ~isempty(GTpos)
    est = zeros(size(map,2),2);
    for ii = 1:size(map,2)
        est(ii,:) = map(ii).m(:)';
    end
    if ~isfield(params,'GOSPA_p'), params.GOSPA_p = 2; end
    if ~isfield(params,'GOSPA_c'), params.GOSPA_c = 150; end
    gospa_val = gospa(est,GTpos,params.GOSPA_p,params.GOSPA_c);
    map_count = size(map,2);
elseif isfield(map,'m') && ~isempty(map)
    gospa_val = NaN;
    map_count = size(map,2);
else
    gospa_val = NaN;
    map_count = 0;
end
end
