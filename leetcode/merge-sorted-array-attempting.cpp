// https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int lastIndexOffset = 0, indexOffset;

        for (int i = 0; i < n; i++) {
            if (nums2[i] >= nums1[m - 1 + lastIndexOffset]) {
                // m - 1 + lio + 1 = m + lio
                nums1[m + lastIndexOffset] = nums2[i];
                lastIndexOffset++;
                continue;
            }

            indexOffset = 0;
            
            for (int j = 0; j < m; j++) {
                if (nums1[j] > nums2[i]) {
                    nums1[j + indexOffset - 1] = nums2[i]; 
                    indexOffset++;
                    continue;
                }
                nums1[j] = nums1[j - indexOffset];
            }
        }
    }
};
