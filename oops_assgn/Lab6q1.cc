#include <iostream>

class Polygon {
public:
  Polygon(double d1 = 0.0, double d2 = 0.0): dim1(d1), dim2(d2) {}
  void set_value(double d1, double d2) {
    dim1 = d1; dim2 = d2;
  }
  virtual double calculate_area() = 0;

protected:
  double getDim1() { return dim1; }
  double getDim2() { return dim2; }

private:
  double dim1;
  double dim2;
};

class Rectangle: public Polygon {
public:
  Rectangle(double h, double w): Polygon(h, w) {}
  
  double calculate_area() {
    return (double)(Polygon::getDim1() * Polygon::getDim2());
  }
};

class Triangle: public Polygon {
public:
  Triangle(double h, double w): Polygon(h, w) {}
  
  double calculate_area() {
    return (double)(0.5 * Polygon::getDim1() * Polygon::getDim2());
  }
};

int main() {
  Polygon* rect = new Rectangle(10, 20);
  std::cout << "Area Rectangle: " << rect->calculate_area() << "\n";

  Polygon* trig = new Triangle(10, 20);
  std::cout << "Area Triangle: " << trig->calculate_area() << "\n";

  return 0;
}
