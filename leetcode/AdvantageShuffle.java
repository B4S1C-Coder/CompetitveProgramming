import java.util.Arrays;

class Solution {
    public int[] advantageCount(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        int[] result = new int[nums1.length];

        // nums2 is sorted but also not sorted
        Integer[] sortedNums2Indices = new Integer[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            sortedNums2Indices[i] = i;
        }
        Arrays.sort(sortedNums2Indices, (a, b) -> Integer.compare(nums2[a], nums2[b]));
        
        int letf = 0, right = nums1.length - 1;

        for (int i = nums1.length - 1; i >= 0; i--) {
            int k = sortedNums2Indices[i];

            // Highest element of nums1, has advantage against the K-th element of nums2
            // Here we basically determine the best (i, j) : i E nums1, j E nums2 & advantage est.
            if (nums1[right] > nums2[k]) {
                // Basically, for we establish advantage for K-th index, we move right pointer back
                result[k] = nums1[right--];
            } else {
                // Advantage is not established for K-th index, we move left pointer ahead
                result[k] = nums1[letf++];
            }
        }

        return result;
    }
}

public class AdvantageShuffle {
  public static void main(String[] args) {
    Solution solution = new Solution();
    int[] answer = solution.advantageCount(new int[]{2, 7, 11, 15}, new int[]{1, 10, 4, 11});

    for (int i: answer) {
      System.out.println(i);
    }
  }
} 
