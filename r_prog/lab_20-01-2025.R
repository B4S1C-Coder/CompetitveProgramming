x <- c(10, 15, 25, 20, 35)
max(x)
min(x)
plot(x, ,'l')
colors <- c('red','green','blue')
barplot(x, xlab='xlabel', ylab='ylabel', col=colors)
colors2 <- c('red','green','blue','purple','pink')
pie(x, labels=c('x1','x2','x3','x4','x5'), col=colors2)

a <- c("a","b","c","d")
b <- c(2,3,4,5)
barplot(b, names.arg=a, density=45, col="purple")
pie(b, labels=a, col=colors2, density=45)
hist(b)
boxplot(b)

f = function(y, n, p) {
  exp1 = choose(n,y)
  exp2 = (p^y)*(1-p)^(n-y)
  return (exp1 * exp2)
}

r <- f(2, 6, 1/3)
r

#t <- seq(0, 10, 1)
t <- 0:6
s <- f(t, 6, 0.3)
plot(t, s, type='l')
s2 <- f(t, 3, 0.4)
s2
lines(t, s2, col="blue")

# Define the function
f <- function(y, n, p) {
  if (any(y < 0 | y > n)) {
    stop("Values of y must be integers between 0 and n.")
  }
  exp1 <- choose(n, y)
  exp2 <- (p^y) * (1 - p)^(n - y)
  return(exp1 * exp2)
}

# Generate a valid sequence of integers for y
t <- 0:6  # Ensure t is within the range of possible values [0, n]

# Calculate probabilities for the first distribution
s <- f(t, 6, 0.3)

# Check the output of f(t, 6, 0.3)
print(s)

dev.new()

# Plot the first distribution
plot(t, s, type = 'b', pch = 19, xlab = "Number of successes (y)", ylab = "Probability", 
     main = "Binomial Distributions")

# Calculate probabilities for the second distribution
s2 <- f(t, 3, 0.4)

# Check the output of f(t, 3, 0.4)
print(s2)

# Add the second distribution to the same plot
lines(t, s2, col = "blue", type = 'b', pch = 19)
legend("topright", legend = c("n=6, p=0.3", "n=3, p=0.4"), col = c("black", "blue"), 
       lty = c(1,2,3), lwd=c(1,2,2),pch = 19)

# pch: point shape, cex: point size
plot(1:10, pch=104, cex=1)


