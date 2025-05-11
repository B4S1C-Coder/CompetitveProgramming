// Fractional Knapsack via Greedy

#include <numeric>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
#include <string>

template<typename T, typename Func = std::function<std::string(const T&)>>
void printVector(
  const std::vector<T>& _vec,
  Func _func=[](const T& _v) -> std::string { return std::to_string(_v);}
)
{
  for (const T& x: _vec) std::cout << _func(x) << " ";
  std::cout << "\n--------------\n";
}

std::pair<std::vector<double>, double> driver(
  const std::vector<int>& _w, const std::vector<int>& _p, const int _c
)
{
  // Sort based on profit / weight ratio, but also keep th original w & p vectors intact
  std::vector<int> pwIdx(_w.size());
  std::iota(pwIdx.begin(), pwIdx.end(), 0); // --> O(N)
  
  // O(NlogN)
  std::sort(pwIdx.begin(), pwIdx.end(), [&_w, &_p](const int& x, const int& y) {
    return (float)_p[x]/_w[x] > (float)_p[y]/_w[y];
  });

  int rCap = _c;
  double profit = 0.0;
  std::vector<double> sol(_w.size(), 0.0);

  for (const int& i: pwIdx) {
    if (rCap <= 0) break;
    if (_w[i] <= rCap) {
      sol[i] = 1.0;
      rCap -= _w[i];
      profit += _p[i];
    } else {
      sol[i] = (double)rCap / _w[i];
      rCap -= (sol[i] * _w[i]);
      profit += (sol[i] * _p[i]);
    }
  }

  return {sol, profit};
}

int main() {
  std::vector<int> weights = {18, 15, 10};
  std::vector<int> profits = {25, 24, 15};
  
  auto [sol, profit] = driver(weights, profits, 20);
  int idx = 0;

  printVector(weights);
  printVector(profits);
  
  std::cout << "PROFIT: " << profit << "\n";

  printVector(sol, [&idx](const double& s) -> std::string {
    return "(" + std::to_string(idx++) + " -> " + std::to_string(s) + ")";
  });

  return 0;
}
