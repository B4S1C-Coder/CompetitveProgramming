#include <iostream>

class Test {
public:
  Test(int x=0): mx(x) {}
  friend void operator-(Test& x);
  void show() { std::cout << mx << "\n"; }
private:
  int mx;
};

void operator-(Test& x) { x.mx = -x.mx; }

int main() {
  Test x1(69);
  x1.show();
  -x1;
  x1.show();
  return 0;
}
