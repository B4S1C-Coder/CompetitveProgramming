library(BSDA)
traffic <- c(
  14800, 15200, 15050, 14900, 15100, 14950, 15300, 15100, 14700, 15200
)
t.test(traffic, mu=15000)