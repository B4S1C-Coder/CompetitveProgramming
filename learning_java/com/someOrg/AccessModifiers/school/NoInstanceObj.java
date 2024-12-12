package com.someOrg.AccessModifiers.school;

public class NoInstanceObj {
    // By making the constructor private we have made sure that no one
    // can create an instance of this object.

    // This is useful in utility classes / functions where you don't want
    // any instances of the object to be created.
    private NoInstanceObj() {}

    public static int add(int a, int b) {
        return a + b;
    }

    public static void sound() {
        System.out.println("Some sound ...");
    }
}
