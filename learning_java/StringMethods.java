public class StringMethods {
    public static void main(String[] args) {
        String name = "Saksham Mittal";
        int length = name.length();
        char c = name.charAt(5); // You can specify the index you wish to access

        System.out.println(length);
        System.out.println(c);

        String sameName = "Saksham Mittal";
        String differentName = "Some Other Name";
        String differentCase = "sAkSham MiTTal";
        System.out.println(name.equals(sameName)); // true
        System.out.println(differentName.equals(name)); // false
        System.out.println(name.equalsIgnoreCase(differentCase)); // true

        // similar to strcmp in C, in this case we will get ASCII Value (S) - ASCII Value(s)
        System.out.println(name.compareTo(differentCase));

        String substr = name.substring(4, 7); // will contain characters at indices 4,5,6
        System.out.println(substr);

        // Strings are immutable in Java, so methods such as
        // trim(), substring(), toLowerCase(), toUpperCase(), replace() etc. will return a new String
        System.out.println(name.contains("Mit")); // true
        System.out.println(name.contains("aksham")); // true
        System.out.println(name.contains("wnkjdc")); // false

        String bleh = ""; String buah = " ";
        System.out.println(bleh.isEmpty()); // true
        System.out.println(buah.isEmpty()); // false
        System.out.println(bleh.isBlank()); // true
        System.out.println(buah.isBlank()); // true
    }
}
