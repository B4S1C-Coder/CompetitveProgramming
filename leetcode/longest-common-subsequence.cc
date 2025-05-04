#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
  int longestCommonSubsequence(std::string text1, std::string text2) {
    std::vector<std::vector<int>> dpTABLE(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));

    for (int i = 1; i <= text1.size(); i++) {
      for (int j = 1; j <= text2.size(); j++) {
        if (text1[i - 1] == text2[j - 1]) {
          dpTABLE[i][j] = dpTABLE[i - 1][j - 1] + 1;
        } else {
          dpTABLE[i][j] = std::max(dpTABLE[i - 1][j], dpTABLE[i][j - 1]);
        }
      }
    }
  
    return dpTABLE[text1.size()][text2.size()];
  }
};