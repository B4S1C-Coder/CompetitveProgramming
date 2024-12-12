import com.someOrg.Abstraction.Dog;
import com.someOrg.Abstraction.Animal;

// Abstraction is basically hiding internal details.
public class Abstraction {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.sound();

        Animal dog1 = new Dog();
        dog1.sound();

        // You can't create object of abstract class
        // Animal animal = new Animal(); // Error
    }
}
