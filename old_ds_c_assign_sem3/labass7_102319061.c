#include <stdio.h>
#include <limits.h>
#include <math.h>

void insertionSort(int* arr, int size) {
    for (int i = 0; i <= size - 1; i++) {
        int temp = arr[i];
        int j = i;

        while ((j > 0) && (arr[j - 1] > temp)) {
            arr[j] = arr[j - 1];
            j--;
            arr[j] = temp;
        }
    }
}

void shellSort(int* arr, int size) {
    int gap = size / 2;

    while (gap > 0) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i], j;
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
        gap = gap / 2;
    }
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i <= size - 2; i++) {
        int min = i;

        for (int j = i + 1; j <= size - 1; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void radixSort(int* arr, int size) {
    // Determine maximum element
    int max = INT_MAX, i;

    for (i = 0; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    int numDigits = floor(log10(max) + 1);

    for (i = 0; i < numDigits; i++) {
        // Sort the array according to i-th digit
        for (int j = 0; j <= size - 1; j++) {
            int temp = arr[j];
            int k = j;

            int digitTemp = (temp / (int)pow(10, i)) % 10;

            while ((k > 0) && (((arr[k - 1] / (int)pow(10, i)) % 10) > digitTemp)) {
                arr[k] = arr[k - 1];
                k--;
                arr[k] = temp;
            }
        }
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void quickSort(int* arr, int p, int r) {
    int partition(int* arr, int p, int r) {
        int x = arr[r];
        int i = p - 1;

        for (int j = p; j <= r - 1; j++) {
            if (arr[j] < x) {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[r];
        arr[r] = temp;

        return i + 1;
    }

    if (p < r) {
       int q = partition(arr, p, r);
       quickSort(arr, p, q - 1);
       quickSort(arr, q + 1, r);
    }
}

void mergeSort(int* arr, int p, int r) {
    void merge(int* arr, int p, int q, int r) {
        int n1 = q - p + 1;
        int n2 = r - q;
        
        int i, j, k;

        int L[n1];
        int R[n2];

        for (i = 0; i <= n1 - 1; i++) {
            L[i] = arr[p + i];
        }

        for (j = 0; j <= n2 - 1; j++) {
            R[j] = arr[q + 1 + j];
        }

        i = 0; j = 0; k = p;

        while ((i < n1) && (j < n2)) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    if (p < r) {
        int q = floor((p + r)/2);
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main() {
    
    printf("SAKSHAM MITTAL - 102319061\n---------------\n");

    int arr[] = {160, 69, 42, 80, 503, -24, 2, 67};
    // radixSort(arr, 8);

    quickSort(arr, 0, 8);
    printf("Quick Sort:\n");
    printArray(arr, 8);

    return 0;
}
