// There are mainly three types of errors:
// 1) Syntax Errors: self-explanatory
// 2) Logical Errors: You basically wrote incorrect logic. Karna kuch tha kar kuch diya
// 3) Runtime Errors: These errors do not come while compiling but come when the program
// is running. They maybe triggered by an edge case that you didn't plan for or some unexpected
// input or event.

// Execption is an event that disrupts the normal flow of the program. It is an object which is
// thrown at runtime. Exception handling is to handle this exception and resume the normal flow
// of the program.

// Checked and Unchecked Exceptions - Checked are those which are checked at compile time and
// unchecked are those which are not checked at compile time.

// Each class by defualt extends the "Object" class, and whenever you call println on an object,
// the object.toString() method would be called (if you have implemeted it, else Object.toString())

import com.someOrg.core.Student;
import com.someOrg.organizationalException;
import java.util.Scanner;

public class ExceptionHandling {
    public static void main(String[] args) {
        System.out.println(divide(69, 0));

        Student student = new Student();
        System.out.println(student);

        // divide();
        try {
            newDivide(69, 42);
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            System.out.println("This executes regardless of exception");
        }
    }

    public static int divide(int a, int b) {
        try {
            return a / b;
            // You can also use just Exception even then the output will show the name
            // of the specific exception
        } catch (ArithmeticException e) {
            System.out.println("Artithmetic Exception occured.");
            System.out.println(e);
            return -1;
        } catch (Exception e) {
            System.out.println("General Exception occured.");
            System.out.println(e);
            return -1;
        }
    }

    public static int divide() {
        try {
            Scanner scanner = new Scanner(System.in);
            
            System.out.println("Enter a: ");
            int a = scanner.nextInt();

            System.out.println("Enter b: ");
            int b = scanner.nextInt();

            scanner.close();

            System.out.println(a / b);

            return a / b;
            // You can catch multiple exceptions but they have to be disjoint.
            // Refer to the exception heirarchy, i.e. the execptions should
            // NOT have a parent child relationship.

            // This is a multicatch
        } catch (ArithmeticException | NullPointerException e) {
            System.out.println("Artithmetic Exception occured.");
            System.out.println(e);
            return -1;
        } catch (Exception e) {
            System.out.println("General Exception occured.");
            System.out.println(e);
            return -1;
        }
    }

    // Here we make the caller of the function responsible to handle the exception,
    // we tell them that this method will throw an ArithmeticException and a general exception
    public static int newDivide(int a, int b) throws ArithmeticException, Exception {
        if ((a == 69)||(a == 42)||(b == 69)||(b == 42)) {
            throw new organizationalException("Naughty numbers not allowed");
        }
        return a / b;
    }
}
