import com.someOrg.StaticDemo.StaticDemo;

public class StaticKeyword {
    public static void main(String[] args) {
        StaticDemo obj1 = new StaticDemo();
        StaticDemo obj2 = new StaticDemo(7);
        StaticDemo obj3 = new StaticDemo(69);

        System.out.println(StaticDemo.getNumberOfInstances());
    }
}
