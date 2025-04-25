#include <iostream>

class Distance {
public:
  Distance(float x=0, float y=0) : mf(x), mi(y) {}
  Distance operator-() {
    mf = -mf;
    mi = -mi;
    return Distance(mf, mi);
  }
  
  void show() {
    std::cout << "feet = " << mf << ", inches = " << mi << "\n";
  }

private:
  float mf;
  float mi;
};

int main() {
  Distance d1(10, 20);
  -d1;
  d1.show();
  return 0;
}
