// Types of Inner Classes
// Member Inner Classes
// Static Nested Classes
// Local Inner Class
// Anonymous Inner Class

import com.someOrg.InnerClasses.Car;
import com.someOrg.InnerClasses.Computer;
import com.someOrg.InnerClasses.ShoppingCart;
import com.someOrg.InnerClasses.CreditCard;
import com.someOrg.InnerClasses.Payment;
import com.someOrg.InnerClasses.Hotel;

public class InnerClasses {
    public static void main(String[] args) {
        Car car = new Car("Test Model");
        Car.Engine engine = car.new Engine();

        engine.start();
        engine.stop();

        Computer computer = new Computer("DELL", "Inspiron 15", "Windows 10");
        computer.getOs().showInfo();

        Computer.USB usb = new Computer.USB("TYPE-C");
        usb.displayInfo();

        ShoppingCart shoppingCart = new ShoppingCart(69.96);
        CreditCard creditCard = new CreditCard();

        shoppingCart.processPayment(creditCard);

        // This can also be done via anonymous member class as:

        // We implemeted the method inline.
        // This somewhat shares similarities with anonymous functions in other languages
        shoppingCart.processPayment(new Payment() {
            @Override
            public void pay(double amount) {
                System.out.println("Paid INR " + amount + " via Anonymous.");
            }
        });

        Hotel hotel = new Hotel("Blue Moon", 69, 42);
        hotel.reserveRoom("Guest1", 1);
    }
}
