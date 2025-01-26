#include <stdio.h>

void printIntArray(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        printf("%d    ", arr[i]);
    }
    printf("\n");
}

void singleDimensionTest() {
    int myArr[10] = {69, 43, 32, 45, 89, 67, 21, 34, 56};
    int insertionIndex = 2, insertionElement = 100;
    int currentIndex = 8;

    printf("Initial Array: ");
    printIntArray(myArr, 10);

    while (currentIndex >= insertionIndex) {
        myArr[currentIndex + 1] = myArr[currentIndex];

        if (currentIndex == insertionIndex) {
            myArr[currentIndex] = insertionElement;
            break;
        }

        currentIndex--;
    }

    printf("Final Array:   ");
    printIntArray(myArr, 10);
}

void twoDimesionTest() {
    int myArr[4][3] = {
                        {69, 43, 32},
                        {45, 89, 67},
                        {21, 34, 56}
                      };
    int rowInsertIndex = 0, colInsertIndex = 2;
    int insertionElement = 100;

    int currentRowIndex = 2, currentColIndex = 2;
    
    printf("INITIAL MATRIX:\n");

    for (int i = 0; i < 4; i++) {
        printIntArray(myArr[i], 3);
    }

    while (currentRowIndex >= rowInsertIndex) {
        // Edge case, handling the right most elements
        if (currentColIndex == 2) {
            myArr[currentRowIndex + 1][0] = myArr[currentRowIndex][currentColIndex];

            printf("[ DEBUG ] SHIFTED to new row, currentRowIndex = %d, currentColIndex = %d\n", currentRowIndex, currentColIndex);

            if ((currentRowIndex == rowInsertIndex) && (currentColIndex == colInsertIndex)) {
                myArr[currentRowIndex][currentColIndex] = insertionElement;
                break;
            }

            currentColIndex--;
            continue;
        }
        // Standard Case
        myArr[currentRowIndex][currentColIndex + 1] = myArr[currentRowIndex][currentColIndex];

        if ((currentRowIndex == rowInsertIndex) && (currentColIndex == colInsertIndex)) {
            myArr[currentRowIndex][currentColIndex] = insertionElement;
            break;
        }

        if (currentColIndex == 0) {
            currentColIndex = 2;
            currentRowIndex--;
            continue;
        }

        currentColIndex--;
    }

    printf("\nFINAL MATRIX:\n");

    for (int i = 0; i < 4; i++) {
        printIntArray(myArr[i], 3);
    }
}

int main() {
    twoDimesionTest();
    return 0;
}
