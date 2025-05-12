library(BSDA)

before <- c(150, 155, 160, 158, 152, 149, 157, 153, 154, 151, 156, 159)
after  <- c(148, 152, 159, 157, 150, 147, 150, 153, 149, 154, 158, 160)

t.test(before, after, paired=TRUE)