package com.someOrg.AccessModifiers.school;

import java.time.Instant;

// At max only one instance of this class can be created
public class OnlyOneInstance {
    private static OnlyOneInstance obj;
    private long timeOfCreation = Instant.now().getEpochSecond();

    private OnlyOneInstance() {}

    public static OnlyOneInstance getInstance() {
        if (obj == null) {
            obj = new OnlyOneInstance();
        }
        return obj;
    }

    public void instanceMethod() {
        System.out.println("This method is attached to an instance and not the class itself");
    }

    public long getTimeOfCreation() {
        return timeOfCreation;
    }
}
