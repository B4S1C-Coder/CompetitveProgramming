
age <- c(58, 69, 43, 39, 63, 52, 47, 31, 74, 36)
cho <- c(189, 235, 193, 177, 154, 191, 213, 165, 198, 181)

z = lm(cho ~ age)
plot (age, cho)
abline(z)

set.seed(123)
n <- 30
num_samples <- 1000
mu <- 100
sigma <- 15

sample_means <- replicate(num_samples, {
  sample <- rnorm(n, mean = mu, sd = sigma)
  mean(sample)
})

mean(sample_means)
var(sample_means)

sample_mean <- replicate(1000, {
  sample <- rbinom(10, size=10, prob=0.8)
  mean(sample)
})

mean(sample_mean)
skewness(sample_mean)
hist(sample_mean)

sm <- replicate(1000, {
  sample <- rpois(50, lambda=4)
  mean(sample)
})
mean(sm)


em1 <- replicate(1000, {
  sample <- rexp(50, rate=1.5)
  mean(sample)
})

em2 <- replicate(1000, {
  sample <- rexp(10, rate=1.5)
  mean(sample)
})
par(mfrow=c(1,2))
hist(em1)
hist(em2)


emm1 <- mean(em1)

nm <- replicate(1000, {
  sample <- rnorm(60, mean=70, sd=10)
  mean(sample)
})
mean(nm)

gm <- replicate(1000, {
  sample <- rgamma(100, shape=2, rate=1)
  mean(sample)
})

mean(gm)

ft = function(x) { replicate(1000, {
  sample <- rpois(50, lambda=x)
  mean(sample)
})}

fz = function(x) { mean(ft(x)) }

fz(c(4:10))

library(BSDA)
ma <- c(8.2, 7.4, 4.0, 6.3, 5.4, 7.1, 8.4, 5.8, 6.4, 4.9)
mb <- c(8.8, 7.9, 4.2, 5.9, 5.9, 7.5, 6.8, 6.3, 5.2, 5.4)

d = var.test(ma, mb, conf.level=0.99)
d

