#include <iostream>
#include <vector>
#include <string>

std::vector<int> bruteForce(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    int n = text.size(), m = pattern.size();
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) ++j;
        if (j == m) matches.push_back(i);
    }
    return matches;
}

template<typename T>
void printVector(const std::vector<T>& _vec) {
  for (const T& x: _vec) { std::cout << x << " "; }
  std::cout << "\n--------------\n";
}

int main() {
  std::string text = "ABABDABACDABABCABAB", pattern = "ABABCABAB";
  
  std::cout << "TEXT: " << text << "\n";
  std::cout << "PATTERN: " << pattern << "\n";

  std::cout << "Brute Force: ";
  printVector(bruteForce(text, pattern));

  return 0;
}
