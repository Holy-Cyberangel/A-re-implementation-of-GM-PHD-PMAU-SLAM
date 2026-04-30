hold on;
load("Environment_SLAM.mat");
first = true;
for i = 1:size(map,2)
    if first
        plot(map(i).m(1), map(i).m(2), "ro", 'DisplayName', 'Landmarks');
        first = false;
    else
        plot(map(i).m(1), map(i).m(2), "ro", 'HandleVisibility','off');
    end
end
plot(x(1,:), x(2,:), "g-", 'DisplayName', 'Estimated Trajectory');
plot(Robot_Groundtruth(1,:), Robot_Groundtruth(2,:), "r-", 'DisplayName', 'Ground Truth');
plot(Landmark_Groundtruth(:,2), Landmark_Groundtruth(:,3), "b.", 'DisplayName', 'True Landmarks');
legend();