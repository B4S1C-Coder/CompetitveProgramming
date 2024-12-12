import MyClasses.Car;
import MyClasses.Cat;
import MyClasses.Animal;
import MyClasses.Dog;

public class TestMyClasses {
    public static void main(String[] args) {
        Car saddiGaddi = new Car("Black", "Jaguar",
                    "XS4", 2024, 117);
        
        System.out.println(saddiGaddi.getBrand());

        Cat saddiBilli = new Cat();
        saddiBilli.name = "Billo"; // proprty inherited from Animal
        saddiBilli.age = 69; // property inherited from Animal
        saddiBilli.breed = "Calico";

        saddiBilli.printInfo();

        Animal dog = new Dog();
        dog.name = "good boy";
        dog.age = 42;
        // dog.breed = "German Shepherd"; // Error, since parent class Animal has no property breed
        dog.makeSound(); // Bark NOT the output of Animal.makeSound

        // saddiGaddi.brand = "Jaguar";
        // saddiGaddi.colour = "Black";
        // saddiGaddi.model = "XS4";
        // saddiGaddi.speed = 68;
        // saddiGaddi.year = 2024;

        // saddiGaddi.accelerate(1);
        // System.out.println(saddiGaddi.speed);

        // OOPS - Classes & Objects
        // 1) Encapsulation - Bundling of data & methods into a single unit.
        //                    This unit is called class. Also hiding data.
        // 2) Inheritance -  A child class inherits the properties and methods
        //                    the parent class.
        // 3) Polymorphism - You can treat the instance of subclass can be treated as
        //                    instance of super class.
        // 4) Abstraction - Essentially hiding internal details.
    }
}
