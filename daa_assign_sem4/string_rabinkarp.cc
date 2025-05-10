#include <iostream>
#include <vector>
#include <string>

std::vector<int> rabinKarp(const std::string& text, const std::string& pattern, int base = 256, int mod = 101) {
    std::vector<int> matches;
    int n = text.size(), m = pattern.size();
    if (m > n) return matches;
    int h = 1;
    for (int i = 0; i < m - 1; ++i) h = (h * base) % mod;

    int p = 0, t = 0;
    for (int i = 0; i < m; ++i) {
        p = (base * p + pattern[i]) % mod;
        t = (base * t + text[i]) % mod;
    }

    for (int i = 0; i <= n - m; ++i) {
        if (p == t) {
            if (text.substr(i, m) == pattern) matches.push_back(i);
        }
        if (i < n - m) {
            t = (base * (t - text[i] * h) + text[i + m]) % mod;
            if (t < 0) t += mod;
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

  std::cout << "Rabin Karp: ";
  printVector(rabinKarp(text, pattern));

  return 0;
}
