package com.someOrg.Human;

public class Grandparent {
    private String name;
    private int age;

    public Grandparent() {
        System.out.println("GrandParent constructor called");
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void grandparentSpecificMethod() {
        System.out.println("GrandParent specific method called");
    }
}
