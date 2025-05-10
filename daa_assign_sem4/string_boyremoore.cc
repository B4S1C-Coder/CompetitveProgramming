#include <iostream>
#include <vector>
#include <string>

std::vector<int> boyerMoore(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    int n = text.size(), m = pattern.size();
    std::vector<int> badChar(256, -1);

    for (int i = 0; i < m; ++i)
        badChar[(int)pattern[i]] = i;

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) --j;
        if (j < 0) {
            matches.push_back(s);
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } else {
            s += std::max(1, j - badChar[text[s + j]]);
        }
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

  std::cout << "Byore Moore: ";
  printVector(boyerMoore(text, pattern));

  return 0;
}
