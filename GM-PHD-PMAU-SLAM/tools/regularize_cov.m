function P = regularize_cov(P)
    P = (P + P')/2;
    jitter = 1e-9;
    [~,flag] = chol(P);
    while flag ~= 0
        P = P + jitter*eye(size(P,1));
        jitter = jitter*10;
        [~,flag] = chol(P);
    end
end
