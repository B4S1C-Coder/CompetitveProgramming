#include <iostream>
#include <string>

class Test {
public:
  int someDataMemb;
  std::string someMembFunc(int x, int i) { return std::to_string(x + i); }
  void show() {
    std::cout << "Data Member = " << someDataMemb << "\n";
  }
};

int main() {
  // Pointer to Data Member
  int Test::*ptrToDataMemb = &Test::someDataMemb;
  // Pointer to Member Function
  std::string(Test::*ptrToMembFunc)(int, int) = &Test::someMembFunc;

  Test tObj;
  tObj.* ptrToDataMemb = 69;
  std::cout << (tObj.*ptrToMembFunc)(24, 6) << "\n";
  tObj.show();

  std::cout << "----------\n";

  Test* tPtr = new Test;
  tPtr->show();
  tPtr->*ptrToDataMemb = 86;
  std::cout << (tPtr->*ptrToMembFunc)(32, 64) << "\n";
  tPtr->show();

  return 0;
}
