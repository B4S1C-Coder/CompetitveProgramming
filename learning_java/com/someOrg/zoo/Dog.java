package com.someOrg.zoo;

public class Dog extends Animal {
    // Override sound method of parent class
    @Override // Anotation (good practice to write) similar to override keyword in C++
    public void sound() {
        System.out.println("Bhaunk!");
    }
}
