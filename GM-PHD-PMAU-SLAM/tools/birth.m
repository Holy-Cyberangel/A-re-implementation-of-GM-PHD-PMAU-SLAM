function map = birth(x,P, map, Z, params,R)
    n = size(map,2);
    for i = 1:size(Z,2)
        n = n+1;
        map(n).m = x(1:2,1)+rotate_x2w(-x(3))*Z(:,i);
        Jx = [1 0 Z(1,i)*sin(-x(3))-Z(2,i)*cos(-x(3));
              0 1 Z(1,i)*cos(-x(3))+Z(2,i)*sin(-x(3))];
        map(n).P = rotate_x2w(-x(3))*R{i}*rotate_x2w(-x(3))'+Jx*P*Jx';
        % map(n).P = 10*eye(2);
        map(n).w = params.birth_intensity;
    end
end
