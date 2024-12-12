package com.someOrg.AccessModifiers.test;
import com.someOrg.AccessModifiers.school.Student;

public class Test {
    public static void main(String[] args) {
        Student student = new Student();
        // System.out.println(student.age); // ERROR, as age is private
    }
}
