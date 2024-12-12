package SomeDataTypes;

public class Student {
    String name;
    String address;
    int standard;
    int rollNumber;

    public Student(String name, String address, int standard, int rollNumber) {
        this.name = name;
        this.address = address;
        this.standard = standard;
        this.rollNumber = rollNumber;
    }

    public void printInfo() {
        System.out.printf("Name: %s\nAddress: %s\nStandard: %d\nRoll No: %d\n",
            this.name, this.address, this.standard, this.rollNumber);
    }
}
