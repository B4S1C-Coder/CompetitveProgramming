#include <vector>
#include <functional>
#include <string>
#include <iostream>
#include <numeric>
#include <algorithm>

template<typename T, typename Func = std::function<std::string(const T&)>>
void printVector(
  const std::vector<T>& _vec,
  Func _func=[](const T& _v) -> std::string { return std::to_string(_v);}
)
{
  for (const T& x: _vec) std::cout << _func(x) << " ";
  std::cout << "\n--------------\n";
}

std::vector<std::vector<int>> driver(
  const std::vector<int>& _s, const std::vector<int>& _f
)
{
  std::vector<int> sIdx(_s.size());
  std::iota(sIdx.begin(), sIdx.end(), 0);

  std::sort(sIdx.begin(), sIdx.end(), [&_s](const int& x, const int& y) {
    return _s[x] < _s[y];
  });

  std::vector<std::vector<int>> sol = { {} };
  
  for (const int& i: sIdx) {
    bool machineAllocated = false;
    for (std::vector<int>& v: sol) {
      if(!v.empty()) {
        if (_s[i] >= _f[v.back()]) {
          v.push_back(i);
          machineAllocated = true;
        }
      } else {
        v.push_back(i);
        machineAllocated = true;
      }
    }

    if (!machineAllocated) {
      sol.push_back(std::vector<int>({ i }));
    }
  }

  return sol;
}

int main() {
  std::vector<int> start = {1, 5, 3, 4};
  std::vector<int> finish = {4, 9, 5, 6};

  std::vector<std::vector<int>> sol = driver(start, finish);
  
  int machineNo = 0;

  printVector(sol, [&machineNo](const std::vector<int>& _v) -> std::string {
      std::cout << "M-" << machineNo++ << " -> ";
      printVector(_v);
      return "";
  });

  return 0;
}
