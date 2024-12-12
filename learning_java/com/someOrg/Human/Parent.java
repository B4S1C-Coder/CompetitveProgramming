package com.someOrg.Human;

public class Parent extends Grandparent {
    public Parent(int x) {
        System.out.println("Parent constructor called");
    }

    public void parentSpecificMethod() {
        System.out.println("Parent specific method called");
    }
}
