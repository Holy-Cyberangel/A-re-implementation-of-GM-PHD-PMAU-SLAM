% propagate pose
function [x_,P_] = pose_predict(x,P,u,dt,Qu)
    v = u(1);
    w = u(2);
    theta = x(3);
    x_ = zeros(3,1);
    x_(1) = x(1) - v/w*sin(theta) + v/w*sin(theta+w*dt);
    x_(2) = x(2) + v/w*cos(theta) - v/w*cos(theta+w*dt);
    x_(3) = wrap_to_pi_local(theta + w*dt);
    % 利用jacobian matrix计算协方差矩阵
    Fx = [1 0 -v/w*cos(theta)+v/w*cos(theta+w*dt);
          0 1 -v/w*sin(theta)+v/w*sin(theta+w*dt);
          0 0 1];
    Fu = [-1/w*sin(theta) + 1/w*sin(theta+w*dt)  v/w^2*sin(theta) - v/w^2*sin(theta+w*dt) + v/w*dt*cos(theta+w*dt);
           1/w*cos(theta) - 1/w*cos(theta+w*dt) -v/w^2*cos(theta) + v/w^2*cos(theta+w*dt) + v/w*dt*sin(theta+w*dt);
           0 dt];
    % P_ = Fx*P*Fx'+Fu*Qu*Fu';
    P_ = Fx*P*Fx'+Fu*diag([Qu(1,1),Qu(2,2)*1])*Fu';
end

function angle = wrap_to_pi_local(angle)
    angle = mod(angle + pi, 2 * pi) - pi;
end
