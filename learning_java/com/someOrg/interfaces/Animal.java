package com.someOrg.interfaces;

public interface Animal {

    int specialAge = 69;

    // public, abstract are redundant here, you need not mention them
    public abstract void eat();

    void sleep();

    // This method is tied to the interface ONLY
    public static void fudge() {
        System.out.println("Fudging ...");
    }

    // By using default you ensure that by introducing a new method you are not
    // breaking the downstream classes that use this interface. This is essentially
    // a default implementation of the method.
    default void methodYetToBeImpleemented() {
        System.out.println("Work in progress ...");
    }
}
