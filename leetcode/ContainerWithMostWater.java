class Solution {
    public int maxArea(int[] height) {
        int currentMaxArea = 0, i = 0, j = height.length - 1;
        
        while (i < j) {
            int lowerIndex = (height[i] > height[j]) ? j : i;
            int area = height[lowerIndex] * (j - i);

            if (area > currentMaxArea) {
                currentMaxArea = area;
            }

            if (lowerIndex == i) {
                i++;
                continue;
            }

            if (lowerIndex == j) {
                j--;
                continue;
            }
        }

        return currentMaxArea;
    }
}

public class ContainerWithMostWater {
  public static void main(String[] args) {
    Solution solution = new Solution();
    int maxArea = solution.maxArea(new int[]{8,7,2,1});

    System.out.println(maxArea);
  }
}
