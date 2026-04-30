load("data\Configration.mat");
%% 场景设置入口(scene setting)
params.max_components = 200; 
params.fov_angle = pi/2;
params.fov_range = 180;
% params.epsilon = 1e-3;            % 计算位姿协方差是否收敛的阈值
params.monte_carlo = 100;
params.P_D = 0.85;
af = 1;
params.R = diag([(0.8*af)^2 (0.3*pi*af/180)^2]);
% OSPA evaluation parameters
params.GOSPA_p = 2;               
params.GOSPA_c = 20; 
params.model = 2;
params.clutter_rate = params.lambda/ ...
        ((2*params.fov_angle/(2*pi))*pi*params.fov_range^2);
% CI融合
if params.model == 1
    params.iter_max = 8;
% 矩匹配
else
    params.iter_max = 15;
end
%% 优化调参入口（parameters tuning）
params.birth_intensity = 0.005;   % initial weight for newborn components
params.prune_threshold = 0.01;    % pruning threshold
params.merge_threshold = 9.21;     % Mahalanobis-squared merge threshold
% Pose update thresholds
params.PHD_det_keep = 0.05;       
params.PHD_miss_keep = 0.01;     
% Map update thresholds
params.map_detection_add_threshold = 0.05;
params.map_miss_prune_threshold = 0.02;


save("data\Configration.mat","params");