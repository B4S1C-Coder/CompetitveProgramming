library(BSDA)
scores <- c(65, 67, 70, 72, 68, 75, 74, 73)
ks.test(scores, "pnorm", mean=mean(scores), sd=sd(scores))

a <- c(5.5, 6.0, 6.2, 5.8, 6.1)
b <- c(5.0, 5.2, 5.4, 5.3, 5.6)

ks.test(a,b)

x <- chisq.test(c(30, 45, 35), p = rep(1/3, 3))$p.value

if (x >= 0.05) {
  print("Failed to reject null hypothesis. There is not enough evidence to conclude that the colour preferences differ significantly from uniform distribution. So, we can't say if one colour is preferred over others.")
} else {
  print("Rejected null hypothesis. One colour is preferred over others.")
}

sprintf("%f", x)