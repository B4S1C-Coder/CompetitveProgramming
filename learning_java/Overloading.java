import MyClasses.Cat;

public class Overloading {
    public static void main(String[] args) {
        int[] arr = {10,10,10,40,32};
        System.out.println(summation(arr));
        System.out.println(summation("Hello, ", "World!"));
        System.out.println(summation(6.9, 4.2));
        System.out.println(summation(69, 42));
        System.out.println(summation(69,42,72,86,45,34));

        Cat x = new Cat();
        x.name = "Excalibur";

        System.out.println(summation(x).name); // ExcaliburADDED
        System.out.println(x.name);            // ExcaliburADDED

    }

    // Method syntax
    // accessModifier returnType methodName(parameters) { code... }

    // The signature of the function would be
    // methodName(parameters)

    // private static int summation(int[] arr) {
    //     int sum = 0;
    //     for (int i: arr) {
    //         sum += i;
    //     }
    //     return sum;
    // }

    // you can pass an array or any number of integers directly
    private static int summation(int... arr) {
        int sum = 0;
        for (int i: arr) {
            sum += i;
        }
        return sum;
    }

    private static int summation(int a, int b) {
        return a + b;
    }

    private static double summation(double a, double b) {
        return a + b;
    }

    private static String summation(String a, String b) {
        return a.concat(b);
    }

    private static Cat summation(Cat c) {
        c.name = c.name.concat("ADDED");
        return c;
    }
}
