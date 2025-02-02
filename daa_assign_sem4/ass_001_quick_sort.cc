#include <iostream>
#include <vector>
#include <stack>
#include <utility>

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

void quickSort_iterative(std::vector<int>& arr) {
  if (arr.empty()) { return; }

  std::stack<std::pair<int, int>> auxStack;

  int p = 0, r = arr.size() - 1;
  auxStack.push({p, r});

  while (!auxStack.empty()) {
    p = auxStack.top().first;
    r = auxStack.top().second;
    auxStack.pop();
    
    // Set pivot element
    int q = partition(arr, p, r);

    // If element on left side -> push them on stack
    if (q - 1 > p) {
      auxStack.push({p, q - 1});
    }

    // If element on right side -> push on stack
    if (q + 1 < r) {
      auxStack.push({q + 1, r});
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
  std::vector<int> copyMyArr = myArr;

  std::cout << "Input array: ";
  printVector(myArr);

  quickSort_recursive(myArr, 0, myArr.size() - 1);
  quickSort_iterative(copyMyArr);

  std::cout << "Recursive QSort: ";
  printVector(myArr);

  std::cout << "Iterative QSort: ";
  printVector(copyMyArr);

  return 0;
}
