#include <thread>
#include <iostream>

int main() {
  size_t numThreads = std::thread::hardware_concurrency();
  std::cout << "Available threads: " << numThreads << std::endl;
  return 0;
}