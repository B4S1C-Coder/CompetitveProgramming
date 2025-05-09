#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

std::pair<std::vector<float>, float> fractionalKnapsack(std::vector<int>& profits, std::vector<int>& weights, const int cap) {
  std::vector<float> solution(profits.size(), 0.0);
  
  std::vector<int> indices(profits.size());
  for (int i = 0; i < profits.size(); i++) { indices[i] = i; }

  std::sort(indices.begin(), indices.end(), [&profits, &weights](const int a, const int b) {
    return (float)profits[a] / weights[a] > (float)profits[b] / weights[b];
  });

  float remainingCap = cap;
  // Construct solution vector
  for (const int x: indices) {
    if (remainingCap == 0) { break; }
    if (remainingCap >= weights[x]) {
      solution[x] = 1.0;
      remainingCap -= weights[x];
    } else {
      solution[x] = (float)remainingCap / weights[x];
      remainingCap = 0;
    }
  }

  float cost = 0.0;
  // Compute cost
  for (int i = 0; i < solution.size(); i++) {
    cost += profits[i] * solution[i];
  }

  return std::make_pair(solution, cost);
}

template<typename T>
void printVector(const std::vector<T>& _vec) {
  for (const T& x: _vec) { std::cout << x << " "; }
  std::cout << "\n--------------\n";
}


int main() {
  std::vector<int> w = {18, 15, 10};
  std::vector<int> p = {25, 24, 15};
  const int capacity = 20;
  
  std::cout << "Capacity = " << capacity << "\n";

  std::cout << "WEIGHTS: ";
  printVector(w);

  std::cout << "PROFITS: ";
  printVector(p);

  auto [sols, cost] = fractionalKnapsack(p, w, capacity);
  
  std::cout << "SOL    :";
  printVector(sols);

  std::cout << "Cost = " << cost << "\n";
  return 0;
}
