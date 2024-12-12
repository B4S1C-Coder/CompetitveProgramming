// Compile Time Polymorphism or Method Overloading
// method with same signature working differently

// It is called compile time because it is decided at compile time that which
// version of the method you have to call

import com.someOrg.zoo.Animal;
import com.someOrg.zoo.Dog;

class Test {
    public int add(int a, int b) {
        return a + b;
    }

    public int add(int a, int b, int c) {
        return a + b+ c;
    }

    public String add (String a, String b) {
        return a.concat(b);
    }
}

public class Polymorphism {
    public static void main(String[] args) {
        Test t =  new Test();
        System.out.println(t.add(1, 68));

        // We can give the child class a refernce of the parent classes

        // Runtime polymorphism
        Animal dog = new Dog(); // Upcasting
        // JVM will look for sound() in Dog object as dog is an Instance of Dog
        // (though has a refernce of Animal)

        // Only those methods of dog can be called that are also implemented by the
        // parent class i.e. Animal

        // This is Dynamic Method Dispatch
        dog.sound(); // Bhaunk! (output of dog)

        Dog myDog = (Dog)dog; // Downcasting
        myDog.sound();
    }
}
