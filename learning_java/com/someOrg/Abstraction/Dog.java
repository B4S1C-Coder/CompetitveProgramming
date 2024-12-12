package com.someOrg.Abstraction;

// Choose whether to define the abstract methods of the parent class or not
// public abstract class Dog extends Animal{
    
// }

public class Dog extends Animal {
    @Override
    public void sound () {
        System.out.println("Bark!");
    }
}