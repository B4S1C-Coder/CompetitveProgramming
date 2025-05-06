library(BSDA)
x = c(6, 7, 4, 5, 9, 3)
SIGN.test(x, md=5)

y = c(1, 2, 3, 4, 77, 8)
wilcox.test(x, y, paired=TRUE)

SIGN.test(x, y, md=0)

ks.test(x, "pnorm", mean=mean(x), sd=sd(x))
ks.test(x,y)

chisq.test(x, p=rep(1/6, 6))

SIGN.test(c(15.2, 14.8, 15.5, 16.0, 14.9, 15.3, 15.1, 14.7), md=15)
SIGN.test(c(6, 5.5, 6, 6.5, 7), c(7, 6.5, 6.5, 7, 7.5), md=0)
SIGN.test(c(0.8, 0.9, 0.85, 0.95), c(0.75, 0.88, 0.8, 0.9), md=0)

wilcox.test(c(72, 75, 80, 78, 76), c(70, 73, 78, 76, 75), paired=TRUE)
wilcox.test(c(55, 60, 58, 62, 59), c(60, 65, 63, 67, 64), paired=TRUE)
wilcox.test(c(85, 88, 90, 87, 86), c(80, 82, 85, 83, 84), paired=TRUE)

ks.test(c(65, 67, 70, 72, 68, 75, 74, 73), "pnorm", mean=mean(x), sd=sd(x))
ks.test(c(5.5, 6, 6.2, 5.8, 6.1), c(5.0, 5.2, 5.4, 5.3, 5.6))

ks.test(
  rnorm(50, mean=0.01, sd=0.02),
  c(0.01, 0.03, 0.00, -0.01, 0.02, 0.01, -0.02, 0.00, 0.03, 0.01)
)


x = c(120, 130, 110, 140)
probs = c(120/ sum(x), 130 / sum(x), 110 / sum(x), 140 / sum(x))
probs

chisq.test(x, p=probs)


a = c(30, 45, 35)
probs = a / sum(a)
probs

chisq.test(a, p=probs)

chisq.test(c(8, 12, 10, 11, 9, 10), p=rep(1/6, 6))
chisq.test(c(50, 30, 20), p=c(0.4, 0.3, 0.3))


sd(c(0.01, 0.03, 0, -0.01, 0.02, 0.01, -0.02, 0, 0.03, 0.01))

