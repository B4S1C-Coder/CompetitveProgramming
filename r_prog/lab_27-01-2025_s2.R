x <- iris
y <- mtcars

lapply(x[1:4], mean)
lapply(x[1:4], median)
quantile(x, prob=c(0.25, 0.50, 0.75))
lapply(x[1:4], quantile, prob=c(0.25, 0.50, 0.75))

lapply(y[2:11], mean)
lapply(y[2:11], median)
quantile(y[2:11], prob=c(0.25, 0.50, 0.75))
lapply(y[2:11], quantile, prob=c(0.25, 0.50, 0.75))

t = c(0, 1, 2, 3, 4)
pt = c(0.41, 0.37, 0.16, 0.05, 0.01)
expval = sum(t * pt)
expval

f = function(t) { t * 0.1 * exp(-0.1 * t) }
r <- integrate(f, lower=0, upper=Inf)
r$value
f1 = function(t) { (t^2) * 0.1 * exp(-0.1 * t) }
r1 <- integrate(f1, lower=0, upper=Inf)
r1$value
var <- r1$value - (r$value^2)
var

f3 = function(x) { 0.5 * exp(-abs(x)) }
r2 <- integrate(f3, lower=1, upper=10)
f4 = function(x) { 0.5 * x * exp(-abs(x)) }
r3 <- integrate(f4, lower=1, upper=10)
var1 <- r3$value - (r2$value^2)
var1

f5 = function(x, m, s) { (1 / (sqrt(2*pi) * s)) * exp(-(x - m)^2 / 2 * (s^2) ) }
plot(f5(, 0, 2))
