package MyClasses;

public class Dog extends Animal {
    public String breed;
    
    public void printInfo() {
        System.out.printf("Name: %s\nAge: %d\nBreed: %s\n", name, age, breed);
    }

    public void makeSound() {
        System.out.println("Bark!");
    }
}
