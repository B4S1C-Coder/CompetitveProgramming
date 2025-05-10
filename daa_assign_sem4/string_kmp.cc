#include <iostream>
#include <vector>
#include <string>

std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m;) {
        if (pattern[i] == pattern[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}

std::vector<int> KMP(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    auto lps = computeLPS(pattern);
    int i = 0, j = 0, n = text.size(), m = pattern.size();
    while (i < n) {
        if (text[i] == pattern[j]) ++i, ++j;
        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            j ? j = lps[j - 1] : ++i;
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

  std::cout << "KMP: ";
  printVector(KMP(text, pattern));

  return 0;
}
