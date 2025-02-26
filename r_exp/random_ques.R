pmf_noK = function(x, u, b) { exp(-(x-u)/b) / ((1 + exp(-(x-u)/b))^2) }
K = function(u, b) {
  (integrate(pmf_noK, lower=0, upper=Inf, u=u, b=b)$value)^-1
}
kvals <- c(K(0, 2), K(0, 4), K(2, 2))

exp_pmf = function(x, u, b) { x * K(u, b) * pmf_noK(x, u, b) }
EX = function(u, b) { integrate(exp_pmf, lower=0, upper=Inf, u=u, b=b)$value }
exvals <- c(EX(0, 2), EX(0, 4), EX(2, 2))

exp2_pmf = function(x, u, b) { (x^2) * K(u, b) * pmf_noK(x, u, b) }
VX = function(u, b) {
  integrate(exp2_pmf, lower=0, upper=Inf, u=u, b=b)$value - (EX(u, b)^2)
}
vxvals <- c(VX(0, 2), VX(0, 4), VX(2, 2))

kvals
exvals
vxvals

#-------------------------------------------------------------------------------
K = function(u, s) {
  (integrate(function(x, u, s){
    ((1/x) * exp((-1/2) * ((log(x) - u)/s)^2))
  }, lower=0, upper=Inf, u=u, s=s)$value)^-1
}
kvals <- c(K(-1, 1), K(-1, 2), K(2, 2))

EX = function(u, s) {
  integrate(function(x, u, s){
    (x) * K(u, s) * ((1/x) * exp((-1/2) * ((log(x) - u)/s)^2))
  }, lower=0, upper=Inf, u=u, s=s)$value
}
exvals <- c(EX(-1, 1), EX(-1, 2), EX(2, 2))

VX = function(u, s) {
  integrate(function(x, u, s){
    (x^2) * K(u, s) * ((1/x) * exp((-1/2) * ((log(x) - u)/s)^2))
  }, lower=0, upper=Inf, u=u, s=s)$value - (EX(u, s)^2)
}
vxvals <- c(VX(-1, 1), VX(-1, 2), VX(2, 2))

kvals
exvals
vxvals

