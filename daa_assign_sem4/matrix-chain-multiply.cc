#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <climits>

class DynamicProgrammingTable_RowMajor {
public:
  DynamicProgrammingTable_RowMajor(int rows, int cols)
    : m_rows(rows), m_cols(cols), m_underlyingVector(rows * cols) {}

  int& operator()(int arow, int acol) {
    return m_underlyingVector[arow * m_cols + acol];
  }

  const int& operator()(int arow, int acol) const {
    return m_underlyingVector[arow * m_cols + acol];
  }

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

std::pair<DynamicProgrammingTable_RowMajor, DynamicProgrammingTable_RowMajor>
matrixChainMultiplication(const std::vector<int>& matrixOrders)
{
  DynamicProgrammingTable_RowMajor dpTABLE(matrixOrders.size() - 1, matrixOrders.size() - 1);
  DynamicProgrammingTable_RowMajor aux(matrixOrders.size() - 1, matrixOrders.size() - 1);

  for (int i = 0; i < matrixOrders.size() - 1; i++) {
    dpTABLE(i, i) = 0;
  }

  for (int s = 1; s < matrixOrders.size() - 1; s++) {
    for (int i = 0; i < matrixOrders.size() - s; i++) {
      int j = i + s;

      // Determine C(i, j) = min{ C(i,k) + C(k+1,j) + m[i-1]*m[k]*m[j]: i<=k<j }
      dpTABLE(i, j) = INT_MAX;

      for (int k = i; k < j; k++) {
        int q = dpTABLE(i, k) + dpTABLE(k + 1, j) + (
          matrixOrders[i]*matrixOrders[k+1]*matrixOrders[j+1]
        );

        if (q < dpTABLE(i, j)) {
          dpTABLE(i, j) = q;
          aux(i, j) = k;
        }
      }
    }
  }

  return { dpTABLE, aux };
}

int main() {
  const std::vector<int> m = {50, 20, 1, 10, 100};
  auto dpSolution = matrixChainMultiplication(m);

  dpSolution.first.display();

  return 0;
}