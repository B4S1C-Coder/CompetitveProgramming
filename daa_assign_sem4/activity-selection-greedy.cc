#include <vector>
#include <algorithm>
#include <iostream>

int activitySelection(const std::vector<int>& starts, const std::vector<int>& finishes) {
  std::vector<int> indices(starts.size());
  for (int i = 0; i < indices.size(); i++) { indices[i] = i; }

  std::sort(indices.begin(), indices.end(), [&finishes](const int a, const int b){
    return finishes[a] < finishes[b];
  });

  int currenTime = 0, taskCount = 0;
  for (const int x: indices) {
    if (starts[x] >= currenTime) {
      taskCount++;
      currenTime = finishes[x];
    }
  }

  return taskCount;
}

template<typename T>
void printVector(const std::vector<T>& _vec) {
  for (const T& x: _vec) { std::cout << x << " "; }
  std::cout << "\n--------------\n";
}

int main() {
  std::vector<int> st = {1, 5, 3, 4};
  std::vector<int> fn = {4, 9, 5, 6};

  std::cout << "START  :\n";
  printVector(st);

  std::cout << "FINISH :\n";
  printVector(fn);

  std::cout << "Task Count that can be performed: " << activitySelection(st, fn) << "\n";
  return 0;
}
