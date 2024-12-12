package com.someOrg.enums;

// Will eventually get cnverted into a class when it compiles so you can define it's methods
public enum TestEnum {
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY;

    private String secret = "This is a secret";

    public void display() {
        System.out.println(this.name());
    }

    public String getSecret() {
        return secret;
    }

    public void setSecret(String secret) {
        this.secret = secret;
    }
}
