import com.someOrg.interfaces.Dog;
import com.someOrg.interfaces.Animal;

public class Interfaces {
    // Class is a blueprint for an object and interface is a blueprint for the class.
    // While abstract classes can contain abstract and normal methods, interfaces
    // contain only abstract methods and static constants (final).

    // Interfaces allows you to achieve multiple inheritance and abstraction.
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.eat();

        System.out.println(Dog.specialAge);

        Animal.fudge();

        dog.methodYetToBeImpleemented();
    }
}
