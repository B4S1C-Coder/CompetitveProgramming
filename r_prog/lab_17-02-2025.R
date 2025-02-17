x <- c(100, 200, 300, 400, 500, 600)
y <- c(228, 236, 256, 278, 285, 301)
plot(x, y)
lm(y~x)
y1 = 0.1526 * x + 210.6
y1
lines(x, y1)
#data = read.csv(file.choose())
f = expression(t^2 + 3*t + 5)
fp = D(f,"t")
fp
eval(fp, list(t=2))
f1 = function(x) { x^3 - 2*x -5 }
root = uniroot(f1, interval=c(1,3))
root

install.packages("nleqslv")
library(nleqslv)
root1 = nleqslv(2, f1)
root1

f2 = function(x, mu, s) { (1/(((2*pi)^0.5))*s) * exp(-0.5*((x-mu)/s)^2) }
integrate(f2, lower=3, upper=Inf, mu=2, s=3^0.5)$value
integrate(f2, lower=1, upper=9, mu=2, s=3^0.5)$value

f3 = function(k, n, p) { choose(n, k) * (p^k) * (1-p)^(n-k) }
f4 = function(a, n, p) {
  prob = 0
  for (k in (a + 1):n) {
    prob = prob + f3(k, n, p)
  }
  prob
}

f3(3, 10, 0.5)
f4(3, 10, 0.5)
pbinom(3, 10, 0.5)

fib = function (n) {
  if (n == 0 || n == 1) {
    return 1
  } else {
    return fib(n - 1) + fib(n - 2)
  }
}