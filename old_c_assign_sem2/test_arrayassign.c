#include <stdio.h>

int main() {
    int arr[4] = {69, 42, 24, 96};
    int newArr[4];

    printf("Enter array (4 elements): ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &newArr[i]);
    }

    // won't work because array type is not assignable
    // arr = newArr;

    // Assign to the original array and print it
    printf("Modified original array: ");
    for (int j = 0; j < 4; j++) {
        arr[j] = newArr[j];
        printf("%d  ", arr[j]);
    }
    printf("\n");

    return 0;
}