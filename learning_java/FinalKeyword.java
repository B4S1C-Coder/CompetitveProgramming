import com.someOrg.vehicles.Car;

// You cannot use final with constructors as they are not inherited

public class FinalKeyword {
    public static void main(String[] args) {
        Car car = new Car();
        car.printInfo();

        Car car1 = new Car("Dhanno");
        car1.printInfo();

        System.out.println(Car.getNumcars());

        System.out.println(com.someOrg.vehicles.Vehicle.getNumVehicles());
    }    
}
