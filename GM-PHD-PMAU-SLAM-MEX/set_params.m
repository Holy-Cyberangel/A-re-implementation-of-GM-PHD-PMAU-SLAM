load("data\Configration.mat");
%% 场景设置入口(scene setting)
params.max_components = 300;      % cap on number of components after tuning
params.fov_angle = pi/2;
% params.epsilon = 1e-3;            % 计算位姿协方差是否收敛的阈值
params.iter_max = 15;
params.monte_carlo = 100;
params.P_D = 0.85;
% OSPA evaluation parameters
params.GOSPA_p = 2;               
params.GOSPA_c = 20;              

%% 优化调参入口（parameters tuning）
params.birth_intensity = 0.005;   % initial weight for newborn components
params.prune_threshold = 0.01;    % pruning threshold
params.merge_threshold = 9.21;     % Mahalanobis-squared merge threshold
% Pose update thresholds
params.PHD_det_keep = 0.05;       
params.PHD_miss_keep = 0.01;     
% Map update thresholds
params.map_detection_add_threshold = 0.05;
params.map_miss_prune_threshold = 0.01;


save("data\Configration.mat","params");