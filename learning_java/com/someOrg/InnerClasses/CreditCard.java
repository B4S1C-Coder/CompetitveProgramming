package com.someOrg.InnerClasses;

public class CreditCard implements Payment {
    @Override
    public void pay(double amount) {
        System.out.println("Paid INR " + amount);
    }
}
