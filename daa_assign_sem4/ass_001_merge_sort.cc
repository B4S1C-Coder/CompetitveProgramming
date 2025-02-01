#include <iostream>
#include <vector>
#include <cmath>

void merge(std::vector<int>& arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    
    // Copy elements to temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[q + 1 + j];
    }
    
    int i = 0, j = 0, k = p;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements (Only one of them will execute)
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

void mergeSort_recursive(std::vector<int>& arr, int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;  // mid
        mergeSort_recursive(arr, p, q);
        mergeSort_recursive(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int min(int x, int y) {
    return (x < y) ? x : y;
}

void mergeSort_iterative(std::vector<int>& arr) {
    int n = arr.size();
    for (int cs = 1; cs < n; cs = 2 * cs) {
        for (int l = 0; l < n - 1; l += 2 * cs) {
            int mid = min(l + cs - 1, n - 1);
            int r = min(l + 2 * cs - 1, n - 1);
            merge(arr, l, mid, r);
        }
    }
}

void printVector(const std::vector<int>& arr) {
    for (const auto& i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> myArr = {160, 69, 42, 80, 503, -24, 2, 67};
    std::cout << "Input Array: ";
    printVector(myArr);
    
    std::vector<int> copyMyArr = myArr;
    
    mergeSort_recursive(myArr, 0, myArr.size() - 1);
    mergeSort_iterative(copyMyArr);
    
    std::cout << "Recursive result: ";
    printVector(myArr);
    std::cout << "Iterative result: ";
    printVector(copyMyArr);
    
    return 0;
}
