import java.util.Scanner;

public class PrintlnVsPrintVsPrintf {
    public static void main(String[] args) {
        // System is a class that provides access to the system runtime
        // and things such as input/output streams, environment variables and other
        // externally defined.

        // out is a member of the System class which provides us access to the output stream
        // this is why we use it to print to the console.

        // println automatically adds a new line character \n after printing the provided arg
        System.out.println("Hello, world!");

        // print will not add a new line character \n after printing the provided arg
        System.out.print("Test");
        System.out.print("Next Statement");

        Scanner scan = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String name = scan.next();
        System.out.printf("Hello, %s\n", name);

        System.out.print("Enter first number: ");
        int a = scan.nextInt();
        System.out.print("Enter second number: ");
        int b = scan.nextInt();

        // printf is similar to printf of C
        System.out.printf("Sum of %d and %d = %d\n", a, b, a + b);

        // Once closed you cannot reopen a scanner object on System.in for the remainder of the program
        // if you have other parts that require user input, you can pass the scanner object and close it
        // only when you no longer need user input or are terminating the program.
        scan.close();
    }
}

// Format Specifier	Conversion Applied
// %%	Inserts a % sign
// %x %X	Integer hexadecimal
// %t %T	Time and Date
// %s %S	String
// %n	Inserts a newline character
// %o	Octal integer
// %f	Decimal floating-point
// %e %E	Scientific notation
// %g	Causes Formatter to use either %f or %e, whichever is shorter
// %h %H	Hash code of the argument
// %d	Decimal integer
// %c	Character
// %b %B	Boolean
// %a %A	Floating-point hexadecimal