package MyClasses;

// Cat class inherits Animal class
// Cat class is a child class of the parent class Animal
public class Cat extends Animal {
    public String breed;

    public void printInfo() {
        System.out.printf("Name: %s\nAge: %d\nBreed: %s\n", name, age, breed);
    }
    // Re-implemented inherited method accordingly
    // Override the original makeSound
    public void makeSound() {
        System.out.println("Meow!");
    }
}
