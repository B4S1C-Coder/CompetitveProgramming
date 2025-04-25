#include <iostream>

class Rectangular {
public:
  Rectangular(float r=0.0, float c=0.0) : mr(r), mc(c) {}
  void show() { std::cout << mr << " + j" << mc << "\n"; }
private:
  float mr;
  float mc;
};

class Polar {
public:
  Polar(float mgn=0.0, float ang=0.0) : mg(mgn), ag(agn) {}
  void show() { std::cout << mg << "<" << ag << "\n"; }
  
private:
  float mg;
  float ag;
};
