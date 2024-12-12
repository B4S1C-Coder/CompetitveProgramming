package com.someOrg.InnerClasses;

public class Computer {
    private String brand;
    private String model;

    private OperatingSystem os;

    public Computer(String brand, String model, String osName) {
        this.brand = brand;
        this.model = model;
        this.os = new OperatingSystem(osName);
    }

    public OperatingSystem getOs() {
        return os;
    }

    public String getBrand() {
        return brand;
    }

    public String getModel() {
        return model;
    }

    // Attached to the outer class itself and not an instance of it.
    public static class USB {
        private String type;

        public USB(String type) {
            this.type = type;
        }
        
        public String getType() {
            return type;
        }

        public void displayInfo() {
            System.out.println("USB Type: " + this.type);
        }
    }

    public class OperatingSystem {
        private String osName;

        public OperatingSystem(String osName) {
            this.osName = osName;
        }

        public void showInfo() {
            System.out.println("Model: " + model);
            System.out.println("Brand: " + brand);
            System.out.println("OS   : " + osName);
        }
    }
}
