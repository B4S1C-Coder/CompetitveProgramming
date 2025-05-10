#include <iostream>
#include <vector>
#include <limits>

int optimalBST(const std::vector<int>& freq) {
    int n = freq.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    std::vector<int> prefixSum(n + 1, 0);

    for (int i = 0; i < n; ++i)
        prefixSum[i + 1] = prefixSum[i] + freq[i];

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = std::numeric_limits<int>::max();
            int totalFreq = prefixSum[j + 1] - prefixSum[i];
            for (int r = i; r <= j; ++r) {
                int left = (r > i) ? dp[i][r - 1] : 0;
                int right = (r < j) ? dp[r + 1][j] : 0;
                dp[i][j] = std::min(dp[i][j], left + right + totalFreq);
            }
        }
    }
    return dp[0][n - 1];
}

template<typename T>
void printVector(const std::vector<T>& _vec) {
  for (const T& x: _vec) { std::cout << x << " "; }
  std::cout << "\n--------------\n";
}

int main() {
    std::vector<int> freq = {34, 8, 50}; // frequencies for sorted keys
    std::cout << "FREQUENCIES: ";
    printVector(freq);
    std::cout << "Minimum cost of optimal BST: " << optimalBST(freq) << "\n";
    return 0;
}

