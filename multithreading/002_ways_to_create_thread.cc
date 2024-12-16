// Functional pointers were covered in 001

// Important:
// If we create multiple threads, it is not guranteed which one will start first.

#include <thread>
#include <iostream>

// Functor (function object), non-static member function, static member function
class Foo {
public:
  void operator ()(int x) { std::cout << x << "\n"; }

  void nonStaticMemberFunc(int x) { std::cout << x << "\n"; }

  static void staticMemberFunc(int x) { std::cout << x << "\n"; }
};

int main() {

  // Via lambda functions
  auto fun = [](int x) {
    std::cout << x << "\n";
  };

  Foo fooInstance;

  std::thread lambdaThread(fun, 69);
  std::thread functorThread((Foo()), 69);
  std::thread nonStaticThread(&Foo::nonStaticMemberFunc, &fooInstance, 69);
  std::thread staticThread(&Foo::staticMemberFunc, 69);

  lambdaThread.join();
  functorThread.join();
  nonStaticThread.join();
  staticThread.join();

  return 0;
}
