#include <iostream>
#include <vector>

int binarySearch_iterative(const std::vector<int>& arr, const int target) {
  int low = 0;
  int high = arr.size() - 1;
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] > target) {
      high = mid - 1;
      continue;
    } else {
      low = mid + 1;
      continue;
    }
  }

  return -1;
}

int binarySearch_recursive(const std::vector<int>& arr, const int target, int low, int high) {
  if (high >= low) {
    int mid = (low + high) / 2;

    if (arr[mid] == target) {
      return mid;
    }

    if (arr[mid] > target) {
      return binarySearch_recursive(arr, target, low, mid - 1);
    }

    return binarySearch_recursive(arr, target, mid + 1, high);
  }
  return -1;
}

void printVector(const std::vector<int>& arr) {
  for (auto& i: arr) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}

int main() {
  const std::vector<int> myArr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const int k1 = 8, k2 = 12;

  std::cout << "SAKSHAM MITTAL - 102319061\n";
  std::cout << "Input array: ";
  printVector(myArr);

  std::cout << "Searching target element: " << k1 << "\n";

  std::cout << "Iterative Result index: " << binarySearch_iterative(myArr, k1) << "\n";
  std::cout << "Recursive Result index: " << binarySearch_recursive(myArr, k1, 0, myArr.size() - 1) << "\n";

  std::cout << "Searching target element: " << k2 << "\n";
  
  std::cout << "Iterative Result index: " << binarySearch_iterative(myArr, k2) << "\n";
  std::cout << "Recursive Result index: " << binarySearch_recursive(myArr, k2, 0, myArr.size() - 1) << "\n";

  return 0;
}
