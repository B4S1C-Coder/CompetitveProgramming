#include <vector>
#include <functional>
#include <string>
#include <iostream>
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

std::vector<int> driver(const std::vector<int>& _s, const std::vector<int>& _f) {
  std::vector<int> fIdx(_s.size());
  std::iota(fIdx.begin(), fIdx.end(), 0);

  std::sort(fIdx.begin(), fIdx.end(), [&_f](const int& x, const int& y){
    return _f[x] < _f[y];
  });

  std::vector<int> sol;
  int prevFinishTime = -1;

  for (const int& i: fIdx) {
    if (_s[i] >= prevFinishTime) {
      sol.push_back(i);
      prevFinishTime = _f[i];
    }
  }

  return sol;
}

int main() {
  std::vector<int> start = {0, 1, 3, 8, 8, 2, 12, 5, 3, 5, 6};
  std::vector<int> finish = {6, 4, 5, 11, 12, 13, 14, 7, 8, 9, 10};

  std::vector<int> sol = driver(start, finish);
  printVector(sol);

  return 0;
}
