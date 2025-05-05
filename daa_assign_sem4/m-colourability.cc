#include <vector>
#include <iostream>

class RowMajorMatrix {
public:
  RowMajorMatrix(int rows, int cols)
    : m_rows(rows), m_cols(cols), m_underlyingVector(rows * cols) {}

  int& operator()(int arow, int acol) {
    return m_underlyingVector[arow * m_cols + acol];
  }

  const int& operator()(int arow, int acol) const {
    return m_underlyingVector[arow * m_cols + acol];
  }

  inline constexpr int rows() { return m_rows; }
  inline constexpr int cols() { return m_cols; }

  void display() {
    std::cout << "X | ";
    for (int i = 0; i < m_cols; i++) {
      std::cout << i << " ";
    }

    std::cout << "\n";

    for (int i = 0; i < m_rows; i++) {
      std::cout << i << " | ";
      for (int j = 0; j < m_cols; j++) {
        std::cout << (*this)(i, j) << " ";
      }
      std::cout << "\n";
    }

    std::cout << "\n";
  }

private:
  std::vector<int> m_underlyingVector;
  int m_rows;
  int m_cols;
};

template<typename T>
void printVector(const std::vector<T>& _vec) {
  for (const T& x: _vec) { std::cout << x << " "; }
  std::cout << "\n--------------\n";
}

void nextValue(RowMajorMatrix& graph, std::vector<int>& x, int m, int k) {
  do {
    // Next highest colour
    x[k] = (x[k] + 1) % (m + 1);
    if (x[k] == 0) {
      return; // All colours used
    }
    int j;
    for (j = 1; j < graph.rows(); j++) {
      if (graph(k, j) != 0 && x[k] == x[j]) {
        break;
      }
    }

    if (j == graph.rows()) {
      return; // New colour found
    }

  } while (true); // Try to find another colour
}

void mColourability_backtracking(RowMajorMatrix& graph, std::vector<int>& x, int m, int k) {
  do {
    nextValue(graph, x, m, k);
    // New colour not possible
    if (x[k] == 0) { return; }
    if (k == graph.rows()) {
      printVector(x);
      return; // All m colours used
    } else {
      mColourability_backtracking(graph, x, m, k+1);
    }
  } while (true);
}

int main() {
  int n = 4, m = 3;

  RowMajorMatrix g(n + 1, n + 1);

  // Since 1-based indexing so first row and col 0
  for (int i = 0; i <= n; i++) {
    g(0, i) = 0;
    g(i, 0) = 0;
  }

  // Square
  g(1, 2) = g(2, 1) = 1;
  g(1, 3) = g(3, 1) = 1;
  g(2, 4) = g(4, 2) = 1;
  g(3, 4) = g(4, 3) = 1;

  std::vector<int> x(n + 1, 0);
  mColourability_backtracking(g, x, m, 1);

  return 0;
}