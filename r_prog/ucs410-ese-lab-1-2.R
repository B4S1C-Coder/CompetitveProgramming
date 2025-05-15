library(BSDA)
drug_a <- c(10, 12, 13, 11, 14)
drug_b <- c(8, 9, 12, 14, 15, 10, 9)
t.test(drug_a, drug_b, alternative = "greater")

manufacturer <- c(132, 134, 129, 129, 130, 132)
competitor <- c(129, 132, 129, 138)
var.test(manufacturer, competitor, alternative = "less")
