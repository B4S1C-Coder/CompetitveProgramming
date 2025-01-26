#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2;
    
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        heapify(arr, n, largest);
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0]; 
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("SAKSHAM MITTAL, 102319061, HEAP SORT, ASSIGNMENT - 9\n--------------\n");
    int arr[] = {9, 4, 3, 8, 10, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Heap Sort: ");
    printArray(arr, n);

    return 0;
}
