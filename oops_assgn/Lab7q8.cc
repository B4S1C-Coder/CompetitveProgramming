#include <iostream>

class Test {
public:
  Test(float f=0.0): mf(f) {}
  operator float() { return mf; }
  void show() { std::cout << mf << "\n"; }
private:
  float mf;
};

int main() {
  Test t = 9.9f;
  t.show();
  return 0;
}
