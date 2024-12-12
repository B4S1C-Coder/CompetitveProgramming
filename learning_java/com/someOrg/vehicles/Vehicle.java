package com.someOrg.vehicles;

public class Vehicle {
    private static int numVehicles = 0;

    private int wheels;

    private String name;

    public Vehicle() {
        numVehicles++;
    }

    // This method cannot be overriden now because of final keyword
    public final void sayNaughtyNumber() {
        System.out.println(69);
    }

    public static int getNumVehicles() {
        return numVehicles;
    }

    protected void setWheels(int wheels) {
        this.wheels = wheels;
    }

    protected void setName(String name) {
        this.name = name;
    }

    protected int getWheels() {
        return wheels;
    }

    protected String getName() {
        return name;
    }

    protected void printInfo() {
        System.out.println(this.name+" has "+this.wheels+" wheels.");
    }
}

// No one can extend this class
final class premiumVehicle extends Vehicle {
    public void saySomething() {
        System.out.println("Premium!");
    }
}