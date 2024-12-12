package com.someOrg.core;

public class Student {
    // property / field / instance variable
    private String m_name;
    private int m_rollNo;
    private int m_age;
    public String school;

    // Custom constructor, we don't specify a return type
    public Student() {
        this.m_name = "Default Name";
        this.m_rollNo = 38383;
        this.m_age = 10;
        this.school = "Default School";
    }

    public Student(String name, int rollNo, int age, String school) {
        this.m_age = age;
        this.m_rollNo = rollNo;
        this.school = school;
        this.m_name = name;
    }

    @Override
    public String toString() {
        return String.format("Student(%s, %d, %d, %s)", this.m_name,
            this.m_age, this.m_rollNo, this.school);
    }

    // behaviour
    public void printInfo() {
        System.out.printf("Name: %s\nAge: %d\nRoll No: %d\n", m_name, m_age, m_rollNo);
    }

    public int rollNo() {
        return m_rollNo;
    }
    public int rollNo(int newRollNo) {
        if (newRollNo <= 0) {
            throw new IllegalArgumentException("Roll Number must be greater than 0.");
        }
        m_rollNo = newRollNo;
        return m_rollNo;
    }

    public String name() {
        return m_name;
    }
    public String name(String newName) {
        m_name = newName;
        return m_name;
    }
    public int age() {
        return m_age;
    }
    public int age(int newAge) {
        if (newAge <= 0) {
            throw new IllegalArgumentException("Age must be greater than 0.");
        }
        m_age = newAge;
        return m_age;
    }
}
