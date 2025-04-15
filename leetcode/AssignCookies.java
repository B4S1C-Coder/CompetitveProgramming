import java.util.Arrays;

class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g); Arrays.sort(s);
        int statisfied = 0, i = g.length - 1, j = s.length - 1;

        while (i >= 0 && j >= 0) {
            if (g[i] <= s[j]) {
                statisfied++;
                i--; j--;
                continue;
            }
            i--;
        }

        return statisfied;
    }
}

public class AssignCookies {
  public static void main(String[] args) {
    Solution solution = new Solution();
    int result = solution.findContentChildren(new int[]{1, 2, 3}, new int[]{1, 1});

    System.out.println(result);
  }
}
