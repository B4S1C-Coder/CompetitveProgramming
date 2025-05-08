#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

std::pair<std::vector<int>, int> jobSeqWithDeadline(const std::vector<int>& profits, const std::vector<int>& deadlines) {
  std::vector<int> indices(profits.size());
  for (int i = 0; i < indices.size(); i++) { indices[i] = i; }

  std::sort(indices.begin(), indices.end(), [&profits](const int a, const int b){
    return profits[a] > profits[b];
  });

  int maxDeadline = *std::max_element(deadlines.begin(), deadlines.end());
  std::vector<int> slots(maxDeadline + 1, -1);

  int totalProfit = 0;

  for (const int x: indices) {
    for (int d = deadlines[x]; d >0; d--) {
      if (slots[d] == -1) {
        slots[d] = x;
        totalProfit += profits[x];
        break;
      }
    }
  }

  return {slots, totalProfit};
}

template<typename T>
void printVector(const std::vector<T>& _vec) {
  for (const T& x: _vec) { std::cout << x << " "; }
  std::cout << "\n--------------\n";
}

int main() {
  std::vector<int> p = {100, 19, 27, 25, 15};
  std::vector<int> d = {2, 1, 2, 1, 3};

  auto [slots, totalProfit] = jobSeqWithDeadline(p, d);

  std::cout << "PROFITS  : ";
  printVector(p);

  std::cout << "DEADLINES: ";
  printVector(d);

  std::cout << "SLOTS    : ";
  printVector(slots);

  std::cout << "Total Profit: " << totalProfit << "\n";

  return 0;
}
