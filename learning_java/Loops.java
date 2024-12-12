public class Loops {
    public static void main(String[] args) {
        int i = 0;

        while (i < 5) {
            System.out.println(i);
            i++;
        }

        System.out.println("Starting do-while loop");

        i = 0;
        do {
            System.out.println(i);
            i++;
        } while (i < 5);

        System.out.println("Starting for loop");
        for (i= 0; i < 5; i++) {
            System.out.println(i);
        }

        for (i = 0; i < 6; i++) {
            System.out.println((int)Math.pow(10, i));
        }

        for (i = 1; i < 11; i++) {
            System.out.printf("7 * %d = %d\n", i, 7*i);
        }

        int n = 46734633;
        int j = 0;

        while (true) {
            int k = n / (int)Math.pow(10, j);
            System.out.println(k);
            if (k == 0) {
                System.out.println("Number of digits = " + Integer.toString(j));
                break;
            }
            j++;
        }
    }
}
