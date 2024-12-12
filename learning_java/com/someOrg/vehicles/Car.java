package com.someOrg.vehicles;

// const is a reserved keyword in Java but has no semantics associated with it
// in the Java specification and the ticket related to that was closed in 2005,
// so const correctness would probably never come into Java and you may NOT be
// able to use const as a variable identifier.
public class Car extends Vehicle {

    private static int numCars = 0;

    // final is essentially the const of Java
    public final int speedLimit = 269;
    public final int something;

    public Car() {
        this.something = 69;
        super.setWheels(4);
        super.setName("Default Car");
        numCars++;
    }

    public Car(String name) {
        this.something = 69;
        super.setWheels(4);
        super.setName(name);
        numCars++;
    }

    @Override
    public void printInfo() {
        System.out.println("Car");
        super.printInfo();
    }

    public static int getNumcars() {
        return numCars;
    }

}
