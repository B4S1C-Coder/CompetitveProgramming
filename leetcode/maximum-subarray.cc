class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return nums[0];
        }

        // int maxSum = (nums[0] > nums[0] + nums[1]) ? nums[0] : nums[0] + nums[1];
        int maxSum = nums[0];
        int prev = maxSum;

        for (int i = 1; i < nums.size(); i++) {
            int greater = (prev + nums[i] > nums[i]) ? prev + nums[i] : nums[i];
            if (greater > maxSum) { maxSum = greater; }
            prev = greater; 
        }

        return maxSum;
    }
};
