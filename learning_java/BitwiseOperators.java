public class BitwiseOperators {
    public static void main(String[] args) {
        // int a = 5;
        // Binary representation of 5
        // System.out.println(Integer.toBinaryString(a));
        // 00000000 00000000 00000000 00000101

        // Bitwise operators can only work on byte, short, int, long
        // Bitwise Operators are:
        // and &, or |, xor ^, not ~, left shift <<, right shift >>, unsigned right shift >>>

        // Difference between right and unsigned right shift
        // In case of unsigned right shift the left most bit (usually determines sign) is
        // always 0 whereas it will change in case of right shift.

        int c = 5 ^ 4;
        System.out.println("5 ---> " + Integer.toBinaryString(5));
        System.out.println("4 ---> " + Integer.toBinaryString(4));
        System.out.println(c + " ---> " + Integer.toBinaryString(c));
        System.out.println(Integer.toBinaryString(~5));
        System.out.println(Integer.toBinaryString(5 << 1));
        System.out.println(Integer.toBinaryString(5 >> 1));
        System.out.println(5 << 1);
        System.out.println(5 >> 1);
    }    
}
