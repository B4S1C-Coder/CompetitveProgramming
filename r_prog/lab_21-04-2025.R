tt1 = c(120, 130, 125, 128, 122, 127)
tt2 = c(115, 118, 116, 119, 117, 120)

x <- t.test(tt1, tt2, conf.level=0.05)
x

y <- t.test(tt1, tt2, conf.level=0.95)
y

m1 <- c(2.3, 2.5, 2.6, 2.2, 2.4, 2.5, 2.3, 2.4, 2.5, 2.2)
m2 <- c(1.8, 1.9, 2.0, 1.7, 1.9, 1.8, 2.1, 1.8, 2.0, 1.9)

f <- var.test(m1, m2, conf.level=0.95)
f

# p < 0.05 -> reject the null hypothesis, there is significant difference
# p > 0.05 -> no significant difference, do not reject null hyptothesis
# t = (xbar1 - xbar2) / sqrt((s1^2/n1) + (s2^2/n2))
# ratio of var. = 1 -> equal variability, < 1 -> first data more variable, >1 -> second data is more variable

pa <- c(115, 141, 145, 109, 113, 137)
pb <- c(113, 128, 136, 119, 107, 146)

var(pa)
var(pb)

pt <- t.test(pa, pb, conf.level=0.99)
pt

drg1 <- c(10, 12, 13, 11, 14, 0, 0)
drg2 <- c(8, 9, 12, 14, 15, 10, 9)

drgt <- t.test(drg1, drg2, var.equal=FALSE)
drgt

man <- c(132, 134, 129, 129, 130, 132)
com <- c(129, 132, 129, 138, 0, 0)

mct <- var.test(man, com, alternative="less")
mct

q <- c(1340, 1500, 1430, 1440, 1380, 1470, 1290)
w <- c(1540, 1480, 1390, 1450, 1440, 1350, 1520, 1400, 1600)

var(q)
var(w)

qwt = t.test(q, w, var.equal=TRUE)
qwt

ba <- c(3.2, 3.4, 2.8, 3.0, 3.0, 3.0, 2.8, 2.9, 3.0, 3.0)
bb <- c(3.0, 3.5, 2.9, 3.1, 2.3, 2.0, 3.0, 2.9, 3.0, 4.1)
bf <- var.test(ba, bb)
bf

premod <- c(18, 21, 16, 22, 19, 24, 17, 21, 23, 18, 14, 16, 16, 19, 18, 20, 12, 22, 15, 17)
posmod <- c(22, 25, 17, 24, 16, 29, 20, 23, 19, 20, 15, 15, 18, 26, 18, 24, 18, 25, 19, 16)
var(premod)
var(posmod)
ppt <- t.test(premod, posmod, var.equal=FALSE)
ppt