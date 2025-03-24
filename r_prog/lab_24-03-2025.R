population <- rnorm(1000, mean=50, sd=10)
population

f = function (population, sample_size, num_sample) {
  sample_mean = numeric(num_sample)
  
  for (i in 1:num_sample) {
    sample = sample(population, size=sample_size, replace=TRUE)
    sample_mean[i] = mean(sample)
  }
  return(sample_mean)
}

sample_size = 30
num_sample = 1000
sample_dist = f(population, sample_size, num_sample)

hist(sample_dist)

print("Sample Dist: ")
mean(sample_dist)
sd(sample_dist)

pop <- rlnorm(1000, meanlog=0, sdlog=1)
pop

sdist <- f(pop, 30, 1000)
hist(sdist)

mean(sdist)
sd(sdist)

upop <- runif(1000, min=0, max=1)
upop

sudist <- f(upop, 30, 1000)
hist(sudist)
mean(sudist)
sd(sudist)


ppop <- rpois(1000, 2)
ppop

psdist <- f(ppop, 30, 1000)
hist(psdist)

mean(psdist)
sd(psdist)

f2 = function (lambda, sample_size, num_sample) {
  sample_mean = numeric(num_sample)
  for (i in 1:num_sample) {
    sample = rpois(lambda, sample_size)
    sample_mean[i] = mean(sample)
  }
  return(sample_mean)
}

rpop <- rgamma(1000, shape = 5, scale = 2)
rpop

rsdist <- f(rpop, 30, 1000)
hist(rsdist)

mean(rsdist)
sd(rsdist)

bpop <- rbinom(1000, size=100, prob=0.6)
bpop

bsdist <- f(bpop, 30, 1000)
hist(bsdist)

mean(bsdist)
sd(bsdist)

bpop <- rnbinom(1000, size=100, prob=0.6)
bpop

nbsdist <- f(bpop, 30, 1000)
hist(nbsdist)

mean(nbsdist)
sd(nbsdist)









