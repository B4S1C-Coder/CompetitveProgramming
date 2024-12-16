// There are primarily 5 ways to create threads in C++ :
// 1. Function Pointers
// 2. Lambda Functions
// 3. Functors
// 4. Member Functions
// 5. Static Member Functions

#include <thread>
#include <iostream>
#include <chrono>

size_t evenSum = 0, oddSum = 0;

void evenDriver(size_t limit) {

  auto startTime = std::chrono::high_resolution_clock::now();

  for (size_t i = 0; i < limit; i += 2) {
    evenSum += i;
  }

  if (limit % 2 == 0) {
    evenSum += limit;
  }

  auto stopTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

  std::cout << "Even sum completed in: " << duration.count() << " us\n";
}

void oddDriver(size_t limit) {

  auto startTime = std::chrono::high_resolution_clock::now();

  for (size_t i = 1; i < limit; i += 2) {
    oddSum += i;
  }

  if (limit % 2 != 0) {
    oddSum += limit;
  }

  auto stopTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

  std::cout << "Odd sum completed in: " << duration.count() << " us\n";
}

int main() {
  size_t limit = 190000000;

  auto startTime = std::chrono::high_resolution_clock::now();

  // Threads via function pointers
  std::thread evenThread(evenDriver, limit);
  std::thread oddThread(oddDriver, limit);

  evenThread.join();
  oddThread.join();

  std::cout << "Even Sum: " << evenSum << "\n";
  std::cout << "Odd Sum : " << oddSum << std::endl;

  auto stopTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

  std::cout << "Mulithreaded operation completed in: " << duration.count() << " us\n";

  return 0;
}