// https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=problem-list-v2&envId=array

#include <cstdio>
#include <vector>

using std::vector;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int currElemCount = 0, prevElem = -101;

    // All duplicate instances set to a value beyond the range of nums[i]
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == prevElem)
      {
        currElemCount++;
      }
      else
      {
        prevElem = nums[i];
        currElemCount = 1;
        continue;
      }

      if (currElemCount > 1)
      {
        nums[i] = -101;
      }
    }

    // Remove all instances of -101 since all duplicates were set to -101
    nums.erase(std::remove(nums.begin(), nums.end(), -101), nums.end());
    return nums.size();
  }
};