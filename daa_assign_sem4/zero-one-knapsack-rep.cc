// must be compiled with the flag -std=c++20

#include <vector>
#include <unordered_map>
#include <climits>
#include <iostream>
#include <algorithm>

int computeKValue(
  int w,
  const std::vector<int>& ws,
  const std::vector<int>& ps,
  std::unordered_map<int, int>& cache
)
{
  if (w == 0) { return 0; }
  if (cache.contains(w)) { return cache[w]; }
  
  int currentMax = 0;

  for (int i = 0; i < ws.size(); i++) {
    if (ws[i] <= w) {
      int kw = computeKValue(w - ws[i], ws, ps, cache);
      currentMax = std::max(currentMax, kw + ps[i]);
    }
  }

  return cache[w] = currentMax;
}

void zeroOneKnapsackWithRep(
  std::vector<int>& kVector,
  const std::vector<int>& weights,
  const std::vector<int>& profits,
  int capacity
)
{
  std::unordered_map<int, int> knapsackCache = {{0,0}};

  for (int i = 0; i <= capacity; i++) {
    int kw = computeKValue(i, weights, profits, knapsackCache);
    kVector.push_back(kw);
  }
}

std::vector<int> getSolutionMap(
  const std::vector<int>& kVector,
  const std::vector<int>& weights,
  const std::vector<int>& profits,
  int capacity
)
{
  std::vector<int> solution(weights.size(), 0);
  int remainingCap = capacity;

  // w: W -> 1, each k(w) represents the maximum possible profit for capacity w
  while (remainingCap > 0) {
    // For each k(w) find an item i such that k(w) = k(w - wi) + vi -> if found that i => 1 else i => 0
    for (int i = 0; i < weights.size(); i++) {
      if (weights[i] <= remainingCap && kVector[remainingCap] == kVector[remainingCap - weights[i]] + profits[i]) {
        solution[i]++;
        remainingCap -= weights[i];
        break;
      }
    }
  }

  return solution;
}

template<typename T>
void printVector(const std::vector<T>& _vec) {
  for (const T& x: _vec) { std::cout << x << " "; }
  std::cout << "\n--------------\n";
}

int main() {
  const std::vector<int> w = {2, 3, 4};
  const std::vector<int> p = {3, 4, 5};
  std::vector<int> kVec;

  zeroOneKnapsackWithRep(kVec, w, p, 5);
  std::vector<int> sol = getSolutionMap(kVec, w, p, 5);

  std::cout << "ITEMS  : ";
  printVector(std::vector<int>({0, 1, 2}));

  std::cout << "WEIGHTS: ";
  printVector<int>(w);

  std::cout << "PROFITS: ";
  printVector<int>(p);

  std::cout << "SOL    : ";
  printVector<int>(sol);

  std::cout << "kVector: ";
  printVector(kVec);

  return 0;
}
