package MyClasses;

// In Java, members (fields and methods) with default access
// are only accessible within the same package.

public class Car {
    // Hiding data and providing methods to change only that data that we want to be changed.
    // This is essentially encapsulation here.
    private String m_colour;
    private String m_brand;
    private String m_model;
    private int m_year;
    private int m_speed;

    public Car(String colour, String brand, String model, int year, int speed) {
        m_colour = colour;
        m_brand = brand;
        m_model = model;
        m_year = year;
        m_speed = speed;
    }

    // Getters
    public String getColour() {
        return m_colour;
    }
    public String getBrand() {
        return m_brand;
    }
    public String getModel() {
        return m_model;
    }
    public int getYear() {
        return m_year;
    }
    public int getSpeed() {
        return m_speed;
    }

    // Setters
    public void setColour(String newColour) {
        m_colour = newColour;
    }
    public void accelerate(int accelerateBy) {
        m_speed += accelerateBy;
    }
}
