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