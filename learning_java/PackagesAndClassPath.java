// import MyClasses.Cat;
// import OtherClasses.Cat;

public class PackagesAndClassPath {
    public static void main(String[] args) {
        MyClasses.Cat kitty = new MyClasses.Cat();
        kitty.name = "Bob";
        OtherClasses.Cat kitto = new OtherClasses.Cat();
        System.out.println(kitto);
    }
}
