#include <iostream>
#include <string>

class Shape {
public:
  Shape(double d1, double d2, const std::string& name): md1(d1), md2(d2), mname(name) {}
  virtual double area() = 0;
  virtual void display() = 0;

protected:
  double d1() { return md1; }
  double d2() { return md2; }
  std::string name() { return mname; }

private:
  double md1;
  double md2;
  std::string mname;
};

class Circle: public Shape {
public:
  Circle(double r): Shape(r, 0.0, "Circle") {}

  double area() {
    return (double)(3.14 * Shape::d1() * Shape::d1());
  }

  void display() {
    std::cout << Shape::name() << "( r = " << Shape::d1() << " )\n";
  }
};

class Rectangle: public Shape {
public:
  Rectangle(double h, double w): Shape(h, w, "Rectangle") {}

  double area() {
    return (double)(Shape::d1() * Shape::d2());
  }

  void display() {
    std::cout << Shape::name() << "( h = " << Shape::d1() << " , w = " << Shape::d2() << " )\n";
  }
};

class Triangle: public Shape {
public:
  Triangle(double h, double w): Shape(h, w, "Triangle") {}

  double area() {
    return (double)(0.5 * Shape::d1() * Shape::d2());
  }

  void display() {
    std::cout << Shape::name() << "( h = " << Shape::d1() << " , w = " << Shape::d2() << " )\n";
  }
};



int main() {
  Circle c(10);
  c.display();
  std::cout << c.area() << "\n";

  Rectangle r(10, 20);
  r.display();
  std::cout << r.area() << "\n";

  Triangle t(10, 20);
  t.display();
  std::cout << t.area() << "\n";

  return 0;
}
