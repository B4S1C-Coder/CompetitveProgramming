#include <vector>
#include <algorithm>
#include <iostream>

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

DynamicProgrammingTable_RowMajor zeroOneKnapsackWithoutRepetition(
  const std::vector<int>& weights,
  const std::vector<int>& profits,
  int capacity
)
{
  DynamicProgrammingTable_RowMajor kTable(weights.size() + 1, capacity + 1);
  for (int w = 0; w <= capacity; w++) { kTable(0, w) = 0; }
  for (int j = 0; j <= weights.size(); j++) { kTable(j, 0) = 0; }
  
  for (int j = 1; j <= weights.size(); j++) {
    for (int w = 1; w <= capacity; w++) {
      // j - 1, since actual items start from 1 and not 0
      if (weights[j - 1] > w) {
        kTable(j, w) = kTable(j - 1, w);
      } else {
        kTable(j, w) = std::max(kTable(j - 1, w), kTable(j - 1, w - weights[j - 1]) + profits[j - 1]);
      }
    }
  }

  return kTable;
}

std::vector<int> getSolutionMap(
  const DynamicProgrammingTable_RowMajor& kTable,
  const std::vector<int> weights,
  const std::vector<int> profits,
  int capacity
)
{
  std::vector<int> sol(weights.size(), 0);

  int j = weights.size();
  int w = capacity;

  while (j > 0 && w > 0) {
    if (kTable(j, w) != kTable(j - 1, w)) {
      sol[j - 1] = 1;
      w -= weights[j - 1];
    }
    j--;
  }

  return sol;
}

template<typename T>
void printVector(const std::vector<T>& _vec) {
  for (const T& x: _vec) { std::cout << x << " "; }
  std::cout << "\n--------------\n";
}

int main() {
  const std::vector<int> w = {2, 3, 4};
  const std::vector<int> p = {3, 4, 5};

  DynamicProgrammingTable_RowMajor kTableSol = zeroOneKnapsackWithoutRepetition(w, p, 5);
  std::vector<int> solution = getSolutionMap(kTableSol, w, p, 5);

  std::cout << "ITEMS  : ";
  printVector(std::vector<int>({0, 1, 2}));

  std::cout << "WEIGHTS: ";
  printVector<int>(w);

  std::cout << "PROFITS: ";
  printVector<int>(p);

  std::cout << "SOL    : ";
  printVector<int>(solution);

  std::cout << "DPTABLE:\n";
  kTableSol.display();

  return 0;
}