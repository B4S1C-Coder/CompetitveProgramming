// Mutex: Mutual Exclusion (kind of like the terms on which the threads will access and modify this data)

// RACE CONDITION: It is a situation where or more threads/processes happen to change some common data at the same time,
// naturally due to such modifications in data we might see unexpected behaviour in all the threads/processes.

// To avoid race conditions, we use mutexes especially their lock and unlock.

#include <thread>
#include <iostream>
#include <mutex>

int commonData = 69;
std::mutex m;

void modifyData() {
  m.lock(); // This will suspend the execution of any other threads trying to lock the mutex
  std::cout << "Value after modification: " << ++commonData << " \n"; // This is the critical region where race occurs
  m.unlock(); // This will resume the execution of other threads waiting to lock the mutex
}

int main() {
  std::thread t1(modifyData);
  std::thread t2(modifyData);

  // Ideally we should expect consistent behaviour but  we get either 70,71 or 71,70
  t1.join(); // commonData: 70 (this can be 71 and below can be 70 depending on which thread started first)
  t2.join(); // commonData: 71

  // Mutex won't ensure the "consistent behaviour described above" but guranttees that at a time only one thread
  // will access the common data.

  return 0;
}