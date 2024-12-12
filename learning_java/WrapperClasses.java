// Wrapper classes wrap around the primitve datatypes in java to enhance their functionality

public class WrapperClasses {
    public static void main(String[] args) {
        int x = 69;
        // Integer is the wrapper class that wraps around the primitve datatype int
        System.out.println(Integer.toHexString(x));

        // Example of Autoboxing
        // Automatically the primitive type is getting converted into an object of the wrapper class
        Integer y = 69; // Java automatically performs Integer.vauleOf(1)

        // Unboxing
        int i = y.intValue(); // Wrapper class object gets converted back to primitive type
        int j = y; // Autounboxing

        System.out.println(i);
        System.out.println(j);

        // While this works, toHexString is a static method and must be accessed via Integer
        System.out.println(y.toHexString(x));

        System.out.println(Integer.toHexString(1983892893));

        // IMPORTANT
        // Integer t = null; // Possible
        // int c = null; // Not Possible, ERROR
    }
}
