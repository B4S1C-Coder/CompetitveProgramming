package com.someOrg.StaticDemo;

public class StaticDemo {
    // This is now tied to the class itself and not the instance of the class
    // This is now essentially a memory shared by all the instances

    // Static variables get initiated regradless of if an instance exists or not
    private static int numberOfInstances = 0;

    // Tied to instance of the class and NOT the class itself
    private int instanceProperty = 0;

    static {
        System.out.println("This is inside the static block");
        // You can initialise static variables here, if any logic
        // needs to be performed before they are initialised that
        // can be done here
    }

    public StaticDemo() {
        numberOfInstances++;
    }

    public StaticDemo(int instanceProperty) {
        numberOfInstances++;
        this.instanceProperty = instanceProperty;
    }

    // Static method cannot use non static data member or call non-static
    // method directly, this and super cannot be used here
    public static int getNumberOfInstances() {
        return numberOfInstances;
    }

    public int getInstanceProperty() {
        return instanceProperty;
    }

    public void setInstanceProperty(int instanceProperty) {
        this.instanceProperty = instanceProperty;
    }
}
