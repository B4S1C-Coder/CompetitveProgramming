# Set up the PNG output
output_file <- "output_plot.png"
png(output_file, width = 800, height = 600)

# After plotting, you can close the device
on.exit(dev.off())  # Automatically close the device when the script finishes

# Your normal R code (without modifications)
x <- seq(0, 2*pi, length.out = 100)
y <- sin(x)
plot(x, y, type = "l", col = "blue", lwd = 2, main = "Sine Wave", xlab = "x", ylab = "sin(x)")

