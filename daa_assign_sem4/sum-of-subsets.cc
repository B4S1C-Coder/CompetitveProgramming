#include <vector>
#include <iostream>

template<typename T>
void printVector(const std::vector<T>& _vec) {
  for (const T& x: _vec) { std::cout << x << " "; }
  std::cout << "\n--------------\n";
}

bool bound(int k, int n, int m, const std::vector<int>& w, int s, int r) {
  return (s + r >= m) && (k + 1 <= n && s + w[k + 1] <= m);
}

void sumOfSubsets_backtracking(
  const std::vector<int>& w,   // Provided numbers
  std::vector<int>& x,         // Solution Vector
  int n,                       // Size of w - 1 (accessible elements)
  int m,                       // Target sum
  int s,                       // Summation of w*x till k - 1
  int k,                       // Currently considered element (index)
  int r                        // Summation of w from k to n
)
{
  // Generate left child
  x[k] = 1;
  if (s + w[k] == m) {
    // Subset of numbers for x[i] == 1
    std::vector<int> subset;
    for (int i = 1; i <= n; i++) { if (x[i] == 1) subset.push_back(w[i]); }
    printVector(subset);
  } else if (k + 1 <= n && s + w[k] + w[k + 1] <= m) {
    sumOfSubsets_backtracking(w, x, n, m, s + w[k], k + 1, r - w[k]);
  }

  // Generate right child
  if (k + 1 <= n && bound(k, n, m, w, s, r)) {
    x[k] = 0;
    sumOfSubsets_backtracking(w, x, n, m, s, k + 1, r - w[k]);
  }
}

int main() {
  std::vector<int> w = {0, 5, 10, 12, 13, 15, 18};
  int m = 30;
  
  std::cout << "INPUT -> ";
  printVector(w);

  std::cout << "TARGET SUM = " << m << "\n";

  int n = w.size() - 1;

  std::vector<int> x(n + 1, 0);
  int total = 0;
  for (int i = 1; i <= n; i++) {
    total += w[i];
  }

  sumOfSubsets_backtracking(w, x, n, m, 0, 1, total);
  return 0;
}
