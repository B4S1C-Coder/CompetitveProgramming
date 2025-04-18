#include <iostream>
#include <string>
#include <cmath>

class TraingleBase {
public:
  double area(double a, double b, double c) {
    double s = (a + b + c) / 2;

    return sqrt(s * (s-a) * (s-b) * (s-c));
  }
};

class RightTriangle : public TraingleBase {
public:
  double area(double d1, double d2) {
    return 0.5 * d1 * d2;
  }
};
class EquiTriangle: public TraingleBase {
public:
  double area(double sd) {
    return (sqrt(3) / 4) * (sd * sd);
  }
};

class IsosTriangle: public TraingleBase {
public:
  double area(double d1, double d2) {
    return 0.5 * d1 * d2;
  }
};

int main() {
  TraingleBase t;
  RightTriangle r;
  EquiTriangle eqt;
  IsosTriangle isos;

  std::cout << t.area(3.0, 3.0, sqrt(2) * 3.0) << " " << r.area(3.0, 3.0) <<
    " " << eqt.area(3.0) << " " << isos.area(3.0, 3.0) << "\n";

  return 0;
}

