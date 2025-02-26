# MST - A
#------------------------------ Question - 1 ------------------------------
weibull = function (x, a, b) { (a/b)*((x/b)^(a-1))*exp(-((x/b)^a)) }
x = 1:40
y = weibull(x, 1, 1.5)
plot(x, y, type="l")

y1 = weibull(x, 1, 4)
lines(x, y1, col="red")

y2 = weibull(x, 2, 3)
lines(x, y2, col="blue")

legend("topright",
  legend=c(
    expression(paste(alpha, " = 1, ", beta, " = 1.5")),
    expression(paste(alpha, " = 1, ", beta, " = 4.0")),
    expression(paste(alpha, " = 2, ", beta, " = 3.0"))
  ),
  fill=c("black","red","blue")
)

weibull_integrand <- function (x, a, b) { x * weibull(x, a, b) }
expected <- integrate(weibull_integrand, lower=0, upper=Inf, a=1, b=4)
expected$value

#------------------------------ Question - 2 ------------------------------
k <- solve(0 + 1 + 2 + 3 + 4, 1)
k
ss <- c(0, 1, 2, 3, 4)
pmf = function (x) { k*x }
exp_pmf = function (x) { x * pmf(x) }
expected = sum(exp_pmf(ss))
expected

exp2_pmf = function (x) { (x^2) * pmf(x) }
variance = sum(exp2_pmf(ss)) - (expected^2)
variance

#------------------------------ Question - 3 ------------------------------
t = table(mtcars$cyl)
pie(
  t,]
  labels=paste(names(t), "( ", t, " )", sep=""),
  main="Cylinder Distribution"
)
barplot(t)
grid(nx = NA, ny = NULL, lty = 2, col = "gray")

maxvals = lapply(mtcars, max)
maxvals
minvals = lapply(mtcars, min)
minvals
meanval = lapply(mtcars, mean)
meanval
quantiles = lapply(mtcars, quantile)
quantiles
medianval = lapply(mtcars, median)
medianval