package com.someOrg.interfaces;

public class Dog implements Animal {
    public void eat() {
        System.out.println("eat");
    }

    public void sleep() {
        System.out.println("sleep");
    }

    @Override
    public void methodYetToBeImpleemented() {
        System.out.println("Now Implemented!");
    }
}
