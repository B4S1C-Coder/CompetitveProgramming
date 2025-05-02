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

int main() {
  const std::vector<int> w = {2, 3, 4};
  const std::vector<int> p = {3, 4, 5};
  std::vector<int> kVec;

  zeroOneKnapsackWithRep(kVec, w, p, 5);

  for (const int& x: kVec) {
    std::cout << x << " ";
  }

  std::cout << "\n";

  return 0;
}
