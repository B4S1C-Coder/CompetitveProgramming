#include <iostream>
#include <cmath>

class Base {
public:
  Base(int x = 0, int y = 0): mx(x), my(y) {}

  void operation() {
    double vectorMag = sqrt(pow(mx, 2) + pow(my, 2));
    std::cout << "[ BASE ] mx = " << mx << " my = " << my << "\n";
    std::cout << "[ BASE ] Vector Mag: " << vectorMag << "\n";
  }

  virtual double area() {
    return (double)(mx * my);
  }

  virtual double volume(double additionalDim) = 0;

  void operator+(Base& b) {
    this->mx += b.mx;
    this->my += b.my;
  }

private:
  int mx;
  int my;
};

class Derived: public Base {
public:
  Derived(int a = 20, int b = 20): Base(a, b) {
    this->ma = a;
    this->mb = b;
  }

  void operation() {
    Base::operation();

    std::cout << "[ DERV ] ma = " << ma << " mb = " << mb << "\n";

    double difference = (double)(ma - mb);
    std::cout << "[ DERV ] Diff: " << difference << "\n";
  }

  double volume(double additionalDim) override {
    return (double)(this->ma * this->mb * additionalDim);
  }

  double area() override {
    return (double)(0.5 * ma * mb);
  }

private:
  int ma;
  int mb;
};

int main() {
  Derived b(3, 4), bd(5, 4);
  b.operation();

  std::cout << "------------------\n";

  b + bd;
  b.operation();

  std::cout << "------------------\n";

  Base* bn = new Derived(12, 13);
  bn->operation();

  return 0;
}
