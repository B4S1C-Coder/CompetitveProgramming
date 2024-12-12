class DataTypes {
    public static void main(String[] args) {
        // Primitive datatypes are:
        // whole numbers: byte (-128 to 127), short (-32768 to 32767), int, long
        // decimal numbers: float, double
        // characters: char
        // booleans: boolean
        // int naughtyNumber = 69;
        // If value of long goes beyond the range of integer than you
        // have to specify `l` (small L) at the end
        // long bahutLamba = 2147483648l;
        // System.out.println(bahutLamba);
        // System.out.println(Long.MIN_VALUE);
        // System.out.println(Long.MAX_VALUE);

        // Only use '' for char, "" is for String
        char myChar = 'x';
        System.out.println(myChar);
        // Type casting, syntax similar to C
        System.out.println((int)myChar); // ASCII Code of 'x'
        // You can assign integer in range [0 (null character), 65535 (?)] without typecast
        char heart = (char) 10084;
        char hindiChar = 2309;
        // Variable names can include or start with $
        boolean $isLearning = true;
        System.out.println(heart);
        System.out.println(hindiChar);
        System.out.println($isLearning);
    }
}
