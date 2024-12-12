import SomeDataTypes.Student;

public class StringsDataType {
    public static void main(String[] args) {
        // String is a sequence of characters and is NOT a primitive datatype.
        String name = "Saksham Mittal";
        // Here student is the reference varaible. The memory get allocated for the new Student
        // object and the varaible student stores the address of the heap allocated memory.
        Student student = new Student(name, "Exam Center", 1, 49);
        student.printInfo();

        String x = "Ram"; // This "Ram" will get stored in the String Pool of Java Heap memory
        String a = new String("Ram"); // stores memory address of "Ram" in Heap
        String b = new String(x); // stores memory address of the litreal in x i.e. "Ram" in heap
        
        // Since, Java won't re-allocate memory for them as the litreal
        // "Ram" is already present in the String Pool.
        String c = "Ram"; // This will have the same memory address as that of x
        String d = "Ram"; // This too will have the same memory address as that of x

        // x,c,d will point to the memory location of "Ram" stored in String pool.
        // a,b will point to the memory location of "Ram" stored in heap.

        // This is NOT how you check equality for strings, this is just checking the
        // references and not the actual value.

        System.out.println(a == b); // false, since a and b store different memory addresses
        System.out.println(c == d); // true
        System.out.println(x == d); // true
    }    
}
