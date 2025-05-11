#include <vector>
#include <functional>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
#include <numeric>

template<typename T, typename Func = std::function<std::string(const T&)>>
void printVector(
  const std::vector<T>& _vec,
  Func _func=[](const T& _v) -> std::string { return std::to_string(_v);}
)
{
  for (const T& x: _vec) std::cout << _func(x) << " ";
  std::cout << "\n--------------\n";
}

std::pair<std::vector<int>, int> driver(
  const std::vector<int>& _d, const std::vector<int>& _p
)
{
  std::vector<int> jobOrd(_d.size());
  std::iota(jobOrd.begin(), jobOrd.end(), 0); // O(N)
  
  // Sort in descending order of profits O(NlogN)
  std::sort(jobOrd.begin(), jobOrd.end(), [&_p](const int& x, const int& y) {
    return _p[x] > _p[y];
  });

  int maxDeadline = *std::max_element(_d.begin(), _d.end()); // O(N)
  std::vector<int> slots(maxDeadline, -1);
  int profit = 0, temp;

  for (const int& idx: jobOrd) {
    // Find the latest free slot
    temp = _d[idx] - 1;
    while (slots[temp] != -1 && temp >= 0) temp--;
    if (temp < 0) continue;

    slots[temp] = idx;
    profit += _p[idx];
  }

  return {slots, profit};
}

int main() {
  std::vector<int> deadline = {2, 1, 2, 1, 1};
  std::vector<int> profit = {100, 19, 27, 25, 15};

  auto [sol, p] = driver(deadline, profit);
  
  std::cout << "Deadline: ";
  printVector(deadline);

  std::cout << "Profits: ";
  printVector(profit);
  
  std::cout << "Slots:\n";

  int slotIdx = 0;

  printVector(sol, [&slotIdx](const auto& s) {
    return "(" + std::to_string(slotIdx++) + " --> " + std::to_string(s) + ")";
  });

  std::cout << "Max Profit: " << p << "\n";

  return 0;
}
