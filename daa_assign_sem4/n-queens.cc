#include <iostream>
#include <vector>
#include <cmath>

bool place(const std::vector<int>& x, int k, int i) {
  for (int j = 1; j < k; j++) {
    // Same column or same diagonal
    if (x[j] == i || std::abs(x[j] - i) == std::abs(j - k)) {
      return false;
    }
  }

  return true;
}

bool NQueens_backtracking(int k, int n, std::vector<int>& x) {
  for (int i = 1; i <= n; i++) {
    if (place(x, k, i)) {
      x[k] = i;
      if (k == n) {
        return true; // Solution found
      } else {
        if(NQueens_backtracking(k + 1, n, x)) {
          return true; // Solution found
        }
      }
    }
  }

  return false; // Solution not found
}

template<typename T>
void printVector(const std::vector<T>& _vec) {
  for (const T& x: _vec) { std::cout << x << " "; }
  std::cout << "\n--------------\n";
}

int main() {
  std::vector<int> eightQueens(8 + 1, 0);
  NQueens_backtracking(1, 8, eightQueens);
  printVector(eightQueens);
  return 0;
}