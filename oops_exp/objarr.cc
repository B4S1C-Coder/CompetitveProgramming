#include <iostream>

class Test {
public:
  Test(int x = 69) {
    std::cout << "constructor called, x = " << x << "\n";
  }
};

int main() {
  Test tests[10];
  std::cout << "----------\n";
  Test* dynTests = new Test[10];
  std::cout << "Finished.\n";
  delete[] dynTests;

  if (dynTests == NULL) {
    std::cout << "Yes, equal to NULL.\n";
  }

  if (dynTests == nullptr) {
    std::cout << "Yes, equal to nullptr.\n";
  }

  return 0;
}
