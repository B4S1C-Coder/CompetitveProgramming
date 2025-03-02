#include <iostream>

class Test {
  static int i;
  int num;
public:
  void static getvalue(int);
  Test(int x)
  {
    num = x;  
  }
  void show()
  {
    std::cout << "i = " << i << std::endl;
    std::cout << "num = " << num << std::endl;
  }
};
void Test::getvalue(int x)
{
  i = x;
  i++;
  std::cout << i << std::endl;
}
int Test::i;
int main()
{
  Test::getvalue(0);
  Test T1(10);
  T1.show();
}
