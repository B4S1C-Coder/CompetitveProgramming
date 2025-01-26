#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, int size) {
    int temp, swap = 0;

    for (int i = 0; i < size; i++) {
        swap = 0;
        for (int j = 0; j < size - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }

        if (swap == 0) {
            break;
        }
    }
}

void printArray(int* arr, int size) {
    printf("Array> ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int myArr[8] = {3, -69, -699, -34, 42, 6, 9, 123};
    printArray(myArr, 8);
    bubbleSort(myArr, 8);
    printArray(myArr, 8);
    return 0;
}