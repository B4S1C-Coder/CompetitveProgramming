#include <thread>
#include <iostream>

void fun1() {
  for (int i = 0; i < 200; i++)
    std::cout << "+";
}

void fun2() {
  for (int i = 0; i < 200; i++)
    std::cout << "-";
}

int main() {
  
  std::thread thread1(fun1);
  std::thread thread2(fun2);

  thread1.join();
  thread2.join();

  return 0;
}