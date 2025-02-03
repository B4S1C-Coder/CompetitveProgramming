f <- function(x, mu, s) {
  (1 / (sqrt(2 * pi) * s)) * exp(-((x - mu)^2) / (2 * s^2))
}

a <- seq(-10, 15, 0.1)
y <- f(a, 0, 2)
plot(a, y, type = "l")

y1 <- f(a, 2, 4)
lines(a, y1,col="red")

y2 <- f(a, -2, 3)
lines(a, y2, col="green")

legend("topright",
  legend=c(
    expression(paste(mu, " = 0, ", sigma, " = 2")),
    expression(paste(mu, " = 2, ", sigma, " = 4")),
    expression(paste(mu, " = -2, ", sigma, " = 3"))),
  fill=c("black","red","green"))

fd <- function(x, mu, s) { (x * f(x, mu, s)) }
e <- integrate(fd, lower=-Inf, upper=Inf, mu=2, s=4)
e$value

f1 = function(x, mu, s) { (1/x) * exp(-((log(x) - mu))^2 / (2 * ((s)^2)) ) }
k = function(mu, s) { integrate(f1, lower=0, upper=Inf, mu=mu, s=s)$value^(-1) }
k(-1, 1)
k(-1, 2)
k(2, 2)