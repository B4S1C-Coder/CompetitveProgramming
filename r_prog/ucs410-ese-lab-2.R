library(BSDA)
brand_a <- c(3.2, 3.4, 2.8, 3.0, 3.0, 3.0, 2.8, 2.9, 3.0, 3.0)
brand_b <- c(3.0, 3.5, 2.9, 3.1, 2.3, 2.0, 3.0, 2.9, 3.0, 4.1)
var.test(brand_b, brand_a, alternative = "greater")

pre <- c(18, 21, 16, 22, 19, 24, 17, 21, 23, 18,
         14, 16, 16, 19, 18, 20, 12, 22, 15, 17)
post <- c(22, 25, 17, 24, 16, 29, 20, 23, 19, 20,
          15, 15, 18, 26, 18, 24, 18, 25, 19, 16)

t.test(post, pre, paired = TRUE, alternative = "two.sided")
