#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

std::pair<std::vector<int>, int> jobSeqWithDeadline(const std::vector<int>& profits, const std::vector<int>& deadlines) {
  std::vector<int> indices(profits.size());

  std::sort(indices.begin(), indices.end(), [&profits](const int a, const int b){
    return profits[a] > profits[b];
  });

  int maxDeadline = *std::max_element(deadlines.begin(), deadlines.end());
  std::vector<int> slots(maxDeadline);

  int totalProfit = 0;

  for (const int x: indices) {
    if (slots[deadlines[x]] <= 0) { continue; }
    slots[deadlines[x]] = x;
    totalProfit += profits[x];
  }

  return {slots, totalProfit};
}