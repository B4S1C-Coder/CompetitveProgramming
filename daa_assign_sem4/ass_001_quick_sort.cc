#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int p, int r) {
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

void quickSort_recursive(std::vector<int>& arr, int p, int r) {
  if (p < r) {
    int q = partition(arr, p, r);
    quickSort_recursive(arr, p, q - 1);
    quickSort_recursive(arr, q + 1, r);
  }
}
