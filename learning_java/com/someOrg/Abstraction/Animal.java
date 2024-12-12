package com.someOrg.Abstraction;

// By writing abstract we are telling Java that this class contains some
// methods that have not been implemented and would likely be implemented 
// by child classes that inherit this class (or the child classes can also
// be abstract and choose whether to define the abstract methods of the
// parent class or not).

// You cannot create an object of the abstract class
public abstract class Animal {

    // it becomes accessible within the same class, any class within the
    // same package, and any subclass, irrespective of the package it belongs to

    protected Animal() {
        System.out.println("Animal protected constructor called");
    }

    // Abstract method, does not have a body (or definition).
    public abstract void sound();

    // Abstract classes can have regular methods
    // This is a concrete method (has a body & definition).
    public void sleep() {
        System.out.println("zzz...");
    }
}
