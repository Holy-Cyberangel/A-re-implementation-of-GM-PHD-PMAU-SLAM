load("data\Environment_SLAM.mat");
load("./data/Configration.mat");
addpath("./tools");
addpath("./data");
x = zeros(3,4000);  
x(:,1) = Robot_Groundtruth(:,1);
P = eye(3);
for k = 2:4000
    Robot_Control(1,k-1) = Robot_Control(1,k-1) +randn(1)*sqrt(params.Qu(1,1));
    Robot_Control(2,k-1) = Robot_Control(2,k-1) +randn(1)*sqrt(params.Qu(2,2));
    [x(:,k),P] = pose_predict(x(:,k-1),P,Robot_Control(:,k-1),T,params.Qu);
end
hold on;
plot(x(1,:),x(2,:));
plot(Robot_Groundtruth(1,:),Robot_Groundtruth(2,:));