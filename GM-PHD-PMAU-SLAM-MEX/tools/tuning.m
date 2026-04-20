function map = tuning(map_,params)
    map = struct('m', {}, 'P', {}, 'w', {});
    if ~isfield(map_,'m') || isempty(map_)
        return;
    end

    n = size(map_,2);
    map_pruned = struct('m', {}, 'P', {}, 'w', {});
    cnt = 1;

    % 剪枝
    for i = 1:n
        if map_(i).w > params.prune_threshold
            map_pruned(cnt).m = map_(i).m;
            map_pruned(cnt).P = regularize_cov(map_(i).P);
            map_pruned(cnt).w = map_(i).w;
            cnt = cnt + 1;
        end
    end

    if ~isfield(map_pruned,'m') || isempty(map_pruned)
        return;
    end

    % 合并
    weights = [map_pruned.w];
    [~,order] = sort(weights,'descend');
    used = false(1,size(map_pruned,2));
    cnt = 1;
    for ii = 1:size(order,2)
        i = order(ii);
        if used(i)
            continue;
        end
        used(i) = true;
        members = i;
        Pi = regularize_cov(map_pruned(i).P);
        for jj = ii+1:size(order,2)
            j = order(jj);
            if used(j)
                continue;
            end
            diff = map_pruned(j).m - map_pruned(i).m;
            d2 = diff'/Pi*diff;
            if d2 < params.merge_threshold
                used(j) = true;
                members(end+1) = j; %#ok<AGROW>
            end
        end

        member_weights = [map_pruned(members).w];
        weight_sum = sum(member_weights);
        mean_sum = zeros(2,1);
        for j = 1:size(members,2)
            mean_sum = mean_sum + member_weights(j)*map_pruned(members(j)).m;
        end
        m_bar = mean_sum/weight_sum;

        P_bar = zeros(2,2);
        for j = 1:size(members,2)
            diff = map_pruned(members(j)).m - m_bar;
            P_bar = P_bar + member_weights(j)*(map_pruned(members(j)).P + diff*diff');
        end
        P_bar = P_bar/weight_sum;

        map(cnt).m = m_bar;
        map(cnt).P = regularize_cov(P_bar);
        map(cnt).w = weight_sum;
        cnt = cnt + 1;
    end

    % 控制分量数量
    if isempty(map)
        return;
    end
    [~,order] = sort([map.w],'descend');
    order = order(1:min(params.max_components,size(order,2)));
    map = map(order);
end
