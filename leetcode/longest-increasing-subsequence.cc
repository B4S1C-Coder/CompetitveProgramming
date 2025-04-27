#include <algorithm>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> lis(nums.size());
        lis[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            lis[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                }
            }
        }

        return *std::max_element(lis.begin(), lis.end());
    }
};
