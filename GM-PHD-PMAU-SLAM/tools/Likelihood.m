function L = Likelihood(Z_,Z,S)
    nu = Z-Z_;
    S = regularize_cov(S);
    L = 1/(2*pi*sqrt(det(S)))*exp(-1/2*nu'/S*nu);
end