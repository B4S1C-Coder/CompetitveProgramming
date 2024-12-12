import com.someOrg.zoo.Dog;
import com.someOrg.Human.Child;
import com.someOrg.zoo.Cat;

public class Inheritance {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.printInfo();

        dog.sound();

        Cat cat = new Cat();
        cat.printInfo();

        cat.sound();

        Child child = new Child();
        child.setName("Bachha");
        child.setAge(12);

        System.out.println(child.getName());
        System.out.println(child.getAge());

        child.childSpecificMethod();
    }
}

// Heirarchal Inheritance
// Grandparent ---> Parent ---> Child

// When making a Child object the order in which constructors execute:

// Child constructor requires things from parent constructor which in turn requires things from
// Grandparent constructor

// GrandParent constructor called
// Parent constructor called
// Child constructor called

// Parallel Heirarchal Inheritance
// Animal +-----> Dog
//        +-----> Cat

// Java does NOT allow multiple inheritance

// Class A +----|
// Class B +----+----> Class X (inherits A,B,C)
// Class C +----|

// This is NOT allowed in Java as this introduces ambiguity. For example each of A,B,C might
// define a method called foo(), then which of A.foo(), B.foo(), C.foo() would be called
// when X.foo() is called?

// For such problems Java provides Interfaces