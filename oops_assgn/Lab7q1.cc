#include <iostream>

class Base {
public:
  Base(int data=0): m_data(data) {}

  void show() {
    std::cout << "data = " << m_data << "\n";
  }

//  void operator++(int x) {
//    m_data++;
//  }

  Base operator++(int x) {
    m_data++;
    return Base(m_data);
  }

  operator int() {
    return m_data;
  }
private:
  int m_data;
};

int main() {
  Base b(10);
  b.show();
  Base c = b++;
  b.show();
  std::cout << "-------\n";
  c.show();

  int y = b;
  std::cout << "b = " << y << "\n";

  return 0;
}
