#include <stdio.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) { i++; }
        while (j >= low && arr[j] > pivot)   { j--; }

        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void QuickSort(int* arr, int low, int high) {
    int j;

    if (low < high) {
        j = partition(arr, low, high);
        QuickSort(arr, low, j - 1);
        QuickSort(arr, j + 1, high);
    }
}

int main() {
    int arr[] = {50, 70, 60, 90, 40, 80, 10, 20, 30}, n = 9;

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
