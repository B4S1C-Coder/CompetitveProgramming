public class Arrays {
    public static void main(String[] args) {
        // type[] variableName;
        int[] numbers = {24, 42, 69, 96, 55, 100};
        int[] anotherArray = new int[10];

        // Error index out of bounds
        // anotherArray[11] = 7;
        // System.out.println(anotherArray[11]);

        // Error index out of bounds
        // numbers[11] = 67;
        // System.out.println(numbers[11]);

        // Traversing an array
        for (int i = 0; i < anotherArray.length; i++) {
            anotherArray[i] = i + 24 + (int)Math.pow(2*i, i);
        }

        // for of loop
        for (int i: anotherArray) {
            System.out.println(i);
        }

        // Searching an element (very basic ignore)
        int index = 0;
        for (int i: numbers) {
            if (i == 55) {
                System.out.printf("Found 55 at index %d\n", index);
                break;
            }
            index++;
        }

        // 2D arrays
        // int[][] myMatrix = {
        //     {1, 2, 3},
        //     {4, 5, 6},
        //     {7, 8, 9}
        // };

        // int[][] another2dArray = new int[3][5];

        // Jagged arrays
        // int [][][] myJaggedArray = new int[4][][];

    }
}
