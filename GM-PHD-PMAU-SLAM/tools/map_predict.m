function idx = map_predict(x_,map,params)
    px = x_(1);
    py = x_(2);
    theta = x_(3);
    idx = false(1,size(map,2));
    if isfield(map, 'm')
        for i = 1:size(map,2)
            dx = map(i).m(1) - px;
            dy = map(i).m(2) - py;
            r = sqrt(dx^2+dy^2);
            bearing = mod(atan2(dy,dx)-theta + pi,2*pi) - pi;
            if r <= params.fov_range && abs(bearing) <= params.fov_angle
                idx(i) = true;
            end
        end
    else
        idx = false;
    end
end
