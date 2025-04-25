#include <iostream>

class BiSummation {
public:
  BiSummation(int m, int n): mx(m), my(n) {}
  BiSummation operator+(const BiSummation& bs) { return BiSummation(mx + bs.mx, my + bs.my); }
  BiSummation operator-(const BiSummation& bs) { return BiSummation(mx - bs.mx, my - bs.my); }
  BiSummation operator*(const BiSummation& bs) { return BiSummation(mx * bs.mx, my * bs.my); }
  BiSummation operator/(const BiSummation& bs) { return BiSummation(mx / bs.mx, my / bs.my); }
  
  bool operator==(const BiSummation& bs) { return ((mx + my) == (bs.mx + bs.my)) && (mx == bs.mx) && (my == bs.my); }
  bool operator&&(const BiSummation& bs) { return (mx + my >= 0) && (bs.mx + bs.my >= 0); }
  bool operator||(const BiSummation& bs) { return (mx + my >= 0) || (bs.mx + bs.my >= 0); }
  bool operator& (const BiSummation& bs) { return (mx >= 0) && (my >= 0) && (bs.mx >= 0) && (bs.my >= 0) && (*this && bs); }
  bool operator| (const BiSummation& bs) { return (mx >= 0) || (my >= 0) || (bs.mx >= 0) || (bs.my >= 0) || (*this || bs); }

  void show() {
    std::cout << "mx = " << mx << ", my = " << my << "\n";
  }

private:
  int mx;
  int my;
};

int main() {
  BiSummation bs1(100, 200), bs2(10, 20);
  BiSummation bs3 = bs1 / bs2, bs4 = bs1 * bs2, bs5 = bs1 + bs2, bs6 = bs1 - bs2;
  bs3.show();
  bs4.show();
  bs5.show();
  bs6.show();

  std::cout << (bool)(bs1 == bs2) << "\n";
  std::cout << (bool)(bs1 == bs1) << "\n";
 
  std::cout << (bool)(bs1 && bs2) << "\n";
  std::cout << (bool)(bs1 && bs1) << "\n";
  
  std::cout << (bool)(bs1 || bs2) << "\n";
  std::cout << (bool)(bs1 || bs1) << "\n";

  std::cout << (bool)(bs1 & bs2) << "\n";
  std::cout << (bool)(bs1 & bs1) << "\n";

  std::cout << (bool)(bs1 | bs2) << "\n";
  std::cout << (bool)(bs1 | bs1) << "\n";
  
  return 0;
}
