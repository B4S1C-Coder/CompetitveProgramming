c <- c(12, -90, 34, 5678)
max(c)
min(c)

fact <- function(n) {
  if (n == 1) { return(1) }
  else if (n == 0) { return(0) }
  else if (n < 0) { return("Invalid argument.") }
  else {
    result <- n * fact(n - 1)
    return(result)
  }
}

print(fact(as.integer(readline("Enter a number> "))))

fibonacci <- function(n) {
  if (n == 1) { print(0) }
  else if (n == 2) { print(c(0, 1)) }
  else if (n <= 0) { return("Error") }
  else {
    p1 <- 0
    p2 <- 1

    for (i in 3:n) {
      p3 <- p1 + p2
      print(p3)
      p1 <- p2
      p2 <- p3
    }
  }
}

fibonacci(10)

calculator <- function() {
  print("1) Add")
  print("2) Subtract")
  print("3) Multiply")
  print("4) Divide")

  while (TRUE) {
    choice <- as.integer(readline("Enter choice> "))
    if (choice < 1 || choice > 4 ) {
      print("Invalid choice")
      break
    }
    x <- as.integer(readline("Num1> "))
    y <- as.integer(readline("Num2> "))
    if (choice == 1) { print(x + y) }
    else if (choice == 2) { print(x - y) }
    else if (choice == 3) { print(x * y) }
    else if (choice == 4) { print(x / y) }
  }
}

calculator()
