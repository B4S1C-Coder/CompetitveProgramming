// Use flag -std=c++20 eg. g++ -std=c++20 -o ./bin/a.out a.cc
// Use C++ 20 or more
// https://leetcode.com/problems/two-sum/

#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> lookup;

    for (int i = 0; i < nums.size(); i++) {

      if (lookup.contains(target - nums[i])) {
        std::vector<int> result = {lookup[target - nums[i]], i};
        return result;
      }

      lookup.insert({nums[i], i});
    }

    return std::vector<int>({-1, -1});
  }
};

int main() {
  return 0;
}