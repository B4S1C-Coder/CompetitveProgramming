// Each std::thread in C++, must either be join()ed or detach()ed.
// When you join() a thread:
// --> After executing the thread, it's resources would be transferred back to the parent thread.
// --> The parent thread would then be responsible to decide what / how should these resources be
//      handled. This is why you will see people referring it as "parent thread waiting for child
//      threads to get executed".
// --> This is also referred as transfer of ownership of the execution state of the thread to the
//     parent thread.

// When you detach() a thread:
// --> Unlike join, the std::thread will now become it's own independent thread, kind of similar to
//     a main() function (the default thread) and the OS would be responsible for managing it's
//     resources.

// Initially when you create a std::thread, it state is JOINABLE. When you call either join() or
// detach(), it's state become NON-JOINABLE. When a std::thread goes out of scope, it's destructor:
// --> Checks it is NON-JOINABLE
// --> If join() ed, the join() thing will happen
// --> If detach() ed, the detach() thing will happen
// --> If neither, it will result in std::terminate() being called since you cannot abruptly
//     terminate a thread leaving the underlying resources hanging. (resource leak)
// Obviously you cannot join or detach a NON-JOINABLE thread.

#include <thread>
#include <iostream>
#include <chrono>

void test() {
  std::cout << "Control in test thread...\n";
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

void run() {
  std::cout << "Control in detached thread ...\n";
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main() {

  std::cout << "Before thread.\n";
  std::thread t1(test);                        // Thread state is JOINABLE
  std::thread t2(run);
  std::cout << "Before join after thread.\n";

  if (t2.joinable())
    t2.detach();

  if (t1.joinable())
    t1.join();                                 // Thread state is NOT-JOINABLE

  std::cout << "After join.\n";

  return 0;
}