package com.someOrg.zoo;

public class Animal {
    private String m_name;
    private int m_age;

    public Animal() {
        this.m_name = "Animal";
        this.m_age = 69;
    }

    public Animal(String name, int age) {
        this.m_name = name;
        this.m_age = age;
    }

    public void printInfo() {
        System.out.println(this.m_name);
        System.out.println(this.m_age);
    }

    public String getName() {
        return this.m_name;
    }

    public void setName(String newName) {
        this.m_name = newName;
    }

    public void setAge(int newAge) {
        this.m_age = newAge;
    }

    public int getAge() {
        return this.m_age;
    }

    public void eat() {
        System.out.println("Khaa");
    }

    public void sound() {
        System.out.println("...");
    }
}
