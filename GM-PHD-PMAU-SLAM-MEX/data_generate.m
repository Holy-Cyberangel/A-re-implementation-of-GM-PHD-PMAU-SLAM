%生成附带观测来源的地标观测数据
%假设：雷达的检测范围是180度，150单位距离
load("Environment_SLAM.mat");
load("Configration.mat");
M = params.monte_carlo;
Measurement = cell(M,T_total);
Odometry = cell(M,T_total);
range = 150;
N = 160;
P_D = params.P_D;
%R = diag([1,0.017]);
R = diag([(0.8)^2 (0.3*pi/180)^2]);
for n=1:M
    for i=1:T_total
        % sim.odometry{1,k} = Robot_Control(:,k) + sqrtQ*randn(params.u_dim,1);
        Odometry{n,i} = Robot_Control(:,i) +sqrt(params.Qu)*randn(2,1);
        x=Robot_Groundtruth(1,i);
        y=Robot_Groundtruth(2,i);
        Z = [];
        dx = Landmark_Groundtruth(:,2)-x;
        dy = Landmark_Groundtruth(:,3)-y;
        range2 = sqrt(dx.^2+dy.^2);
        theta = mod(atan2(dy,dx)-Robot_Groundtruth(3,i) + pi,2*pi) - pi;
        for j=1:size(Landmark_Groundtruth(:,1),1)
            r = range2(j)+randn(1)*sqrt(R(1,1));
            bearing = theta(j)+1*randn(1)*sqrt(R(2,2));
            if r<range 
                if abs(bearing) <= params.fov_angle
                    Z(:,end+1)=[r;bearing];
                end
            end
        end
        NN = size(Z,2);
        % roll一个被检测
        detected = rand(1,NN)<=P_D;
        Z = Z(:,detected);
        % roll一个杂波数
        N_clutter = poissrnd(params.lambda,1);
        for j=1:N_clutter
            random_range = sqrt(rand)*range;
            random_angle = (rand*2-1)*pi/2;
            Z(:,end+1)=[random_range;random_angle];
        end
        Z(2,:) = mod(Z(2,:)+pi,2*pi)-pi;
        Measurement{n,i}=Z;
    end
end
save("./data/Measurement.mat","Measurement","range","M","Odometry");
