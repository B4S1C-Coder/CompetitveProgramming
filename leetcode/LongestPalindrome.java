import java.util.HashMap;

class Solution {
    public int longestPalindrome(String s) {
        HashMap<Integer, Integer> letterCount = new HashMap<>();
        s.chars().forEach((x) -> letterCount.merge(x, 1, Integer::sum));

        int longestPalindromeLength = 0;
        boolean encounteredTokenWithSingleCount = false;

        for (HashMap.Entry<Integer, Integer> entry: letterCount.entrySet()) {
            int v = entry.getValue();
            int k = entry.getKey();

            System.out.println("Key: " + (char)k + " , Value: " + v);

            if (v % 2 == 0) {
                System.out.println("Considered Key: " + (char)k);
                longestPalindromeLength += v;
            } else {
                longestPalindromeLength += v - 1;
                if (!encounteredTokenWithSingleCount) {
                    encounteredTokenWithSingleCount = true;
                    longestPalindromeLength++;
                }
            }
        }

        return longestPalindromeLength;
    }
}

public class LongestPalindrome {
  public static void main(String[] args) {
    Solution solution = new Solution();

    int x = solution.longestPalindrome("abccccdd");
    System.out.println(x);
  }
}
