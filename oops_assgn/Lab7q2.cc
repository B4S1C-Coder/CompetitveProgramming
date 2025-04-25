#include <iostream>

class Distance {
public:
  Distance(float x=0, float y=0) : mx(x), my(y) {}
  Distance operator+(Distance& d) {
    return Distance(mx + d.mx, my + d.my);
  }
  
  void show() {
    std::cout << "x = " << mx << ", y = " << my << "\n";
  }

private:
  float mx;
  float my;
};

int main() {
  Distance d1(10, 20), d2(3, 4);
  Distance d3 = d1 + d2;
  d3.show();
  return 0;
}
