import com.someOrg.core.Student;

public class Constructors {
    // Constructor is a special method used to initialize an object. It is called when creating
    // an object and is generally used to set initial values.

    // If you don't make a constructor yourself, a defualt constructor would be made automatically.
    
    public static void main(String[] args) {
        Student st1 = new Student();
        Student st2 = new Student("eded", 12, 12, "2de");

        st1.printInfo();
        st2.printInfo();
    }
}
