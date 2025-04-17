class Solution {
    public int[] diStringMatch(String s) {
        int maxInd = s.length(), len = s.length();
        int minInd = 0, index = 0;
        int[] result = new int[maxInd + 1];

        for (int i = 0; i < len; i++) {
            if (s.charAt(i) == 'I') {
                result[index++] = minInd++;
            } else {
                result[index++] = maxInd--;
            }

            // Last char
            if (i == len - 1) {
                if (s.charAt(i) == 'I') {
                    result[index] = result[index - 1] + 1;
                } else {
                    result[index] = result[index - 1] - 1;
                }
            }
        }

        return result;
    }
}

public class DIStringMatch {
  public static void main(String[] args) {
    String s = new String("IDID");
    Solution solution = new Solution();

    int[] perm = solution.diStringMatch(s);

    for (int i = 0; i < perm.length; i++) {
      System.out.println(perm[i]);
    }
  }
}
