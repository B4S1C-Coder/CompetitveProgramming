package com.someOrg.AccessModifiers.school;

public class Student {
    // Accessibe throughout the package, outside the package, accessible everywhere
    public String name;
    // Accessible only throughout this class
    private int age;

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    // Only accessible throughout this class and to the subclasses that inherit thid class
    // it is NOT ACCESSIBLE OUTSIDE THE CLASS
    protected void foo() {
        System.out.println("bar");
    }
}

// Default i.e. classes with no keyword (public etc.) is accessible only throughout
// this package and not outside it.

class childClass extends Student {
    public void test() {
        // System.out.println(super.age); // ERROR, not accessible as age is private
        super.foo();
    }
}

class insideClass {
    public void test() {
        Student student = new Student();
        // System.out.println(student.age); // ERROR, not accessible as age is private
    }
}
