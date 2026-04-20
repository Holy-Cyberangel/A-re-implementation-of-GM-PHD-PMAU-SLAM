function [xk, Pk, mapOut] = slam_step_codegen(xPrev, PPrev, odom, curMea, mapIn, params, T, isLastStep)
%#codegen
% Single-step core update packaged for MATLAB Coder / MEX.

    [xPred, PBase] = pose_predict_local(xPrev, PPrev, odom, T, params.Qu);
    [Z, Rstack] = preprocess_local(curMea, params.R);

    xCur = xPred;
    PCur = PBase;
    for iter = 1:params.iter_max
        [~, visMap] = split_map_by_fov_local(xCur, mapIn, params.fov_range, params.fov_angle);
        [xCur, PCur] = pose_update_mm_local(xCur, PBase, visMap, Z, params, Rstack, iter);
    end

    [keepMap, visMap] = split_map_by_fov_local(xCur, mapIn, params.fov_range, params.fov_angle);
    [mapTmp, birthIdx] = map_update_local(xCur, PCur, keepMap, visMap, Z, params, Rstack);
    mapTmp = tuning_local(mapTmp, params);

    if isLastStep
        mapOut = mapTmp;
    else
        mapOut = birth_local(xCur, PCur, mapTmp, Z, params, Rstack, birthIdx);
    end

    xk = xCur;
    Pk = regularize_cov_local(PCur);
end

function [xPred, PPred] = pose_predict_local(x, P, u, dt, Qu)
    v = u(1);
    w = u(2);
    theta = x(3);

    xPred = zeros(3,1);
    xPred(1) = x(1) - v / w * sin(theta) + v / w * sin(theta + w * dt);
    xPred(2) = x(2) + v / w * cos(theta) - v / w * cos(theta + w * dt);
    xPred(3) = wrap_to_pi_local(theta + w * dt);

    Fx = [1 0 -v / w * cos(theta) + v / w * cos(theta + w * dt); ...
          0 1 -v / w * sin(theta) + v / w * sin(theta + w * dt); ...
          0 0 1];
    Fu = [-1 / w * sin(theta) + 1 / w * sin(theta + w * dt), ...
           v / w^2 * sin(theta) - v / w^2 * sin(theta + w * dt) + v / w * dt * cos(theta + w * dt); ...
           1 / w * cos(theta) - 1 / w * cos(theta + w * dt), ...
          -v / w^2 * cos(theta) + v / w^2 * cos(theta + w * dt) + v / w * dt * sin(theta + w * dt); ...
           0, dt];

    PPred = Fx * P * Fx' + Fu * diag([Qu(1,1), Qu(2,2) * 3]) * Fu';
end

function [meaXY, Rstack] = preprocess_local(curMea, Rpolar)
    numZ = size(curMea, 2);
    meaXY = zeros(2, numZ);
    Rstack = zeros(2, 2, numZ);
    if numZ == 0
        return;
    end

    r = curMea(1,:);
    theta = curMea(2,:);
    meaXY(1,:) = r .* cos(theta);
    meaXY(2,:) = r .* sin(theta);

    for i = 1:numZ
        J = [cos(theta(i)), -r(i) * sin(theta(i)); ...
             sin(theta(i)),  r(i) * cos(theta(i))];
        Rstack(:,:,i) = J * Rpolar * J';
    end
end

function [keepMap, visMap] = split_map_by_fov_local(x, mapIn, fovRange, fovAngle)
    n = numel(mapIn);
    keepMap = repmat(map_template_local(), 1, max(1, n));
    visMap = repmat(map_template_local(), 1, max(1, n));
    keepCount = 0;
    visCount = 0;

    px = x(1);
    py = x(2);
    theta = x(3);
    for i = 1:n
        dx = mapIn(i).m(1) - px;
        dy = mapIn(i).m(2) - py;
        r = sqrt(dx * dx + dy * dy);
        bearing = mod(atan2(dy, dx) - theta + pi, 2 * pi) - pi;
        if r <= fovRange && abs(bearing) <= fovAngle
            visCount = visCount + 1;
            visMap(visCount) = mapIn(i);
        else
            keepCount = keepCount + 1;
            keepMap(keepCount) = mapIn(i);
        end
    end

    keepMap = resize_map_local(keepMap, keepCount);
    visMap = resize_map_local(visMap, visCount);
end

function [xOut, POut] = pose_update_mm_local(xBase, PBase, mapIn, Z, params, Rstack, iterCnt)
    numMap = numel(mapIn);
    numZ = size(Z, 2);
    if numMap == 0
        xOut = xBase;
        POut = PBase;
        return;
    end

    PD = params.P_D;
    detKeep = params.PHD_det_keep;
    missKeep = params.PHD_miss_keep;
    theta = xBase(3);
    c = cos(theta);
    s = sin(theta);

    sumW = 0;
    xNumer = zeros(3,1);
    for i = 1:numMap
        dx = mapIn(i).m(1) - xBase(1);
        dy = mapIn(i).m(2) - xBase(2);
        Zhat = [c * dx + s * dy; -s * dx + c * dy];
        H = [-c, -s, -dx * s + dy * c; ...
              s, -c, -dx * c - dy * s];

        missW = mapIn(i).w * (1 - PD);
        if missW > missKeep
            sumW = sumW + missW;
            xNumer = xNumer + missW * xBase;
        end

        detRaw = zeros(1, numZ);
        xDet = zeros(3, numZ);
        denom = params.clutter_rate;
        for j = 1:numZ
            S = H * PBase * H' + Rstack(:,:,j);
            K = (PBase * H') / S;
            nu = Z(:,j) - Zhat;
            xDet(:,j) = xBase + K * nu;
            detRaw(j) = likelihood_local(Zhat, Z(:,j), S) * PD * mapIn(i).w;
            denom = denom + detRaw(j);
        end

        if denom > 0
            for j = 1:numZ
                wNorm = detRaw(j) / denom;
                if wNorm > detKeep
                    sumW = sumW + wNorm;
                    xNumer = xNumer + wNorm * xDet(:,j);
                end
            end
        end
    end

    if sumW <= eps
        xOut = xBase;
        POut = PBase;
        return;
    end

    xOut = xNumer / sumW;
    if iterCnt ~= params.iter_max
        POut = PBase;
        return;
    end

    POut = zeros(3,3);
    for i = 1:numMap
        dx = mapIn(i).m(1) - xBase(1);
        dy = mapIn(i).m(2) - xBase(2);
        Zhat = [c * dx + s * dy; -s * dx + c * dy];
        H = [-c, -s, -dx * s + dy * c; ...
              s, -c, -dx * c - dy * s];

        missW = mapIn(i).w * (1 - PD);
        if missW > missKeep
            wFinal = missW / sumW;
            diffMiss = xBase - xOut;
            POut = POut + wFinal * (PBase + diffMiss * diffMiss');
        end

        detRaw = zeros(1, numZ);
        detState = zeros(3, numZ);
        detCov = zeros(3, 3, numZ);
        denom = params.clutter_rate;
        for j = 1:numZ
            S = H * PBase * H' + Rstack(:,:,j);
            K = (PBase * H') / S;
            nu = Z(:,j) - Zhat;
            detState(:,j) = xBase + K * nu;
            detCov(:,:,j) = (eye(3) - K * H) * PBase;
            detRaw(j) = likelihood_local(Zhat, Z(:,j), S) * PD * mapIn(i).w;
            denom = denom + detRaw(j);
        end

        if denom > 0
            for j = 1:numZ
                wNorm = detRaw(j) / denom;
                if wNorm > detKeep
                    wFinal = wNorm / sumW;
                    diffDet = detState(:,j) - xOut;
                    POut = POut + wFinal * (detCov(:,:,j) + diffDet * diffDet');
                end
            end
        end
    end

    POut = regularize_cov_local(POut);
end

function [mapOut, birthIdx] = map_update_local(x, P, keepMap, inMap, Z, params, RstackLocal)
    numZ = size(Z, 2);
    numKeep = numel(keepMap);
    numIn = numel(inMap);

    birthIdx = true(1, numZ);
    cap = max(1, numKeep + numIn * (numZ + 1));
    mapOut = repmat(map_template_local(), 1, cap);
    outCount = 0;
    for i = 1:numKeep
        outCount = outCount + 1;
        mapOut(outCount) = keepMap(i);
    end

    if numIn == 0
        mapOut = resize_map_local(mapOut, outCount);
        return;
    end

    Zmap = zeros(2, numZ);
    Rworld = zeros(2, 2, numZ);
    rot = rotate_x2w_local(-x(3));
    for j = 1:numZ
        Zmap(:,j) = x(1:2) + rot * Z(:,j);
        Jx = [1 0 Z(1,j) * sin(-x(3)) - Z(2,j) * cos(-x(3)); ...
              0 1 Z(1,j) * cos(-x(3)) + Z(2,j) * sin(-x(3))];
        Rworld(:,:,j) = rot * RstackLocal(:,:,j) * rot' + Jx * P * Jx';
    end

    detDen = params.clutter_rate * ones(1, numZ);
    rawLike = zeros(numIn, numZ);
    for i = 1:numIn
        for j = 1:numZ
            S = inMap(i).P + Rworld(:,:,j);
            rawLike(i,j) = likelihood_local(inMap(i).m, Zmap(:,j), S) * params.P_D * inMap(i).w;
            detDen(j) = detDen(j) + rawLike(i,j);
        end
    end

    for i = 1:numIn
        missW = inMap(i).w * (1 - params.P_D);
        if missW > params.map_miss_prune_threshold
            outCount = outCount + 1;
            mapOut(outCount).m = inMap(i).m;
            mapOut(outCount).P = regularize_cov_local(inMap(i).P);
            mapOut(outCount).w = missW;
        end
    end

    for j = 1:numZ
        if detDen(j) <= 0
            continue;
        end
        for i = 1:numIn
            w = rawLike(i,j) / detDen(j);
            if w > params.map_detection_add_threshold
                S = inMap(i).P + Rworld(:,:,j);
                K = inMap(i).P / S;
                nu = Zmap(:,j) - inMap(i).m;
                outCount = outCount + 1;
                mapOut(outCount).m = inMap(i).m + K * nu;
                mapOut(outCount).P = regularize_cov_local((eye(2) - K) * inMap(i).P);
                mapOut(outCount).w = w;
                birthIdx(j) = false;
            end
        end
    end

    mapOut = resize_map_local(mapOut, outCount);
end

function mapOut = tuning_local(mapIn, params)
    n = numel(mapIn);
    if n == 0
        mapOut = repmat(map_template_local(), 1, 0);
        return;
    end

    pruned = repmat(map_template_local(), 1, n);
    prunedCount = 0;
    for i = 1:n
        if mapIn(i).w > params.prune_threshold
            prunedCount = prunedCount + 1;
            pruned(prunedCount).m = mapIn(i).m;
            pruned(prunedCount).P = regularize_cov_local(mapIn(i).P);
            pruned(prunedCount).w = mapIn(i).w;
        end
    end
    if prunedCount == 0
        mapOut = repmat(map_template_local(), 1, 0);
        return;
    end
    pruned = pruned(1:prunedCount);

    weights = zeros(1, prunedCount);
    for i = 1:prunedCount
        weights(i) = pruned(i).w;
    end
    [~, order] = sort(weights, 'descend');

    used = false(1, prunedCount);
    merged = repmat(map_template_local(), 1, prunedCount);
    mergedWeights = zeros(1, prunedCount);
    mergedCount = 0;

    for ii = 1:prunedCount
        idx = order(ii);
        if used(idx)
            continue;
        end
        used(idx) = true;

        members = zeros(1, prunedCount);
        memberCount = 1;
        members(1) = idx;
        Pi = regularize_cov_local(pruned(idx).P);

        for jj = ii + 1:prunedCount
            jdx = order(jj);
            if used(jdx)
                continue;
            end
            diff = pruned(jdx).m - pruned(idx).m;
            d2 = diff' * (Pi \ diff);
            if d2 < params.merge_threshold
                used(jdx) = true;
                memberCount = memberCount + 1;
                members(memberCount) = jdx;
            end
        end

        weightSum = 0;
        meanSum = zeros(2,1);
        for kk = 1:memberCount
            mIdx = members(kk);
            weightSum = weightSum + pruned(mIdx).w;
            meanSum = meanSum + pruned(mIdx).w * pruned(mIdx).m;
        end
        mBar = meanSum / weightSum;

        PBar = zeros(2,2);
        for kk = 1:memberCount
            mIdx = members(kk);
            diff = pruned(mIdx).m - mBar;
            PBar = PBar + pruned(mIdx).w * (pruned(mIdx).P + diff * diff');
        end
        PBar = PBar / weightSum;

        mergedCount = mergedCount + 1;
        merged(mergedCount).m = mBar;
        merged(mergedCount).P = regularize_cov_local(PBar);
        merged(mergedCount).w = weightSum;
        mergedWeights(mergedCount) = weightSum;
    end

    if mergedCount == 0
        mapOut = repmat(map_template_local(), 1, 0);
        return;
    end

    maxKeep = min(params.max_components, mergedCount);
    if mergedCount <= maxKeep
        mapOut = resize_map_local(merged, mergedCount);
        return;
    end

    [~, order] = sort(mergedWeights(1:mergedCount), 'descend');
    mapOut = repmat(map_template_local(), 1, maxKeep);
    for i = 1:maxKeep
        mapOut(i) = merged(order(i));
    end
end

function mapOut = birth_local(x, P, mapIn, Z, params, RstackLocal, birthIdx)
    numZ = size(Z, 2);
    inCount = numel(mapIn);
    mapOut = repmat(map_template_local(), 1, max(1, inCount + numZ));
    outCount = 0;
    for i = 1:inCount
        outCount = outCount + 1;
        mapOut(outCount) = mapIn(i);
    end

    rot = rotate_x2w_local(-x(3));
    for j = 1:numZ
        if ~birthIdx(j)
            continue;
        end
        outCount = outCount + 1;
        mapOut(outCount).m = x(1:2) + rot * Z(:,j);
        Jx = [1 0 Z(1,j) * sin(-x(3)) - Z(2,j) * cos(-x(3)); ...
              0 1 Z(1,j) * cos(-x(3)) + Z(2,j) * sin(-x(3))];
        mapOut(outCount).P = rot * RstackLocal(:,:,j) * rot' + Jx * P * Jx';
        mapOut(outCount).w = params.birth_intensity;
    end

    mapOut = resize_map_local(mapOut, outCount);
end

function mapOut = resize_map_local(mapIn, count)
    if count == 0
        mapOut = repmat(map_template_local(), 1, 0);
    else
        mapOut = mapIn(1:count);
    end
end

function S = rotate_x2w_local(theta)
    S = [cos(theta),  sin(theta); ...
        -sin(theta),  cos(theta)];
end

function P = regularize_cov_local(P)
    P = (P + P') / 2;
    jitter = 1e-9;
    [~, flag] = chol(P);
    while flag ~= 0
        P = P + jitter * eye(size(P, 1));
        jitter = jitter * 10;
        [~, flag] = chol(P);
    end
end

function value = likelihood_local(Zhat, Z, S)
    nu = Z - Zhat;
    S = regularize_cov_local(S);
    value = 1 / (2 * pi * sqrt(det(S))) * exp(-0.5 * (nu' / S) * nu);
end

function angle = wrap_to_pi_local(angle)
    angle = mod(angle + pi, 2 * pi) - pi;
end

function mapItem = map_template_local()
    mapItem = struct('m', zeros(2,1), 'w', 0, 'P', zeros(2,2));
end
