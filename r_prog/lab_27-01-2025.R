x <- iris
x
head(x, 10)
tail(x)
str(x)
x[3, ]
sprintf("Mean Width: %f", mean(x[,2]))
sprintf("Standard Deviation in Width : %f", sd(x[,2]))
summary(x[,2])
quantile(x[,2], prob=c(0.25, 0.50, 0.75))
hist(x[,2],main="Width",col="red")

s <- table(iris$Species)
pie(s, labels=names(s), main='Species Distribution')

barplot(x[,2])
lapply(x[1:4], mean)
lapply(x[1:4], sd)
lapply(x[1:4], quantile)
lapply(x[1:4], var)
IQR(x[,2])
cov(x[,2], x[, 3])

y <- mtcars
y

lapply(x[1:4], mean)
lapply(x[1:4], median)
