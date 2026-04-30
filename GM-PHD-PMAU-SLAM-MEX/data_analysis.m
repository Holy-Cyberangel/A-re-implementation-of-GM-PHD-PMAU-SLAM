clear all;
%load("./data/result_0.95_5_1.mat");
%load("./data/result_0.85_5_1.mat");
load("./data/result.mat");
pos_mean = mean(pos_rmse_trials);
pos_std  = std(pos_rmse_trials);

yaw_mean = mean(yaw_rmse_trials);
yaw_std  = std(yaw_rmse_trials);

gospa_mean = mean(gospa_trials);
gospa_std  = std(gospa_trials);

runtime_mean = mean(runtime);
runtime_std = std(runtime);
