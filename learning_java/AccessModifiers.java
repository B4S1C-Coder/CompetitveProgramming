import com.someOrg.AccessModifiers.school.Student;
import com.someOrg.AccessModifiers.school.NoInstanceObj;
import com.someOrg.AccessModifiers.school.OnlyOneInstance;

public class AccessModifiers {
    public static void main(String[] args) {
        Student student = new Student();
        // System.out.println(student.age); // ERROR, as age is private
        System.out.println(NoInstanceObj.add(2, 67));
        NoInstanceObj.sound();

        // Both instances are actually the same instance that was created the first time.
        OnlyOneInstance myInstance = OnlyOneInstance.getInstance();
        OnlyOneInstance myOtherInstance = OnlyOneInstance.getInstance();
        // myInstance.instanceMethod();

        // Both will have the same time of creation
        System.out.println(myInstance.getTimeOfCreation());
        System.out.println(myOtherInstance.getTimeOfCreation());
    }
}
