// First ever leetcode problem

// https://leetcode.com/problems/two-sum/

// Runtime: 82 ms (beats 20.60%)
// Memory: 12.91 MB (beats 72.05%)
// Complexity: O(N^2)

// Submitted on: 04-09-2024 18:45:13 IST

#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        int index = 0;

        for (int i: nums) {
            std::vector<int>::iterator it = std::find(nums.begin(), nums.end(), target - i);
            if (it != nums.end()) {
                int anotherIndex = std::distance(nums.begin(), it);

                if (anotherIndex == index) {
                    index++;
                    continue;
                }

                result.push_back(index);
                result.push_back(anotherIndex);
                break;
            }
            index++;
        }

        return result;
    }
};
