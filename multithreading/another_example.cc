#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>
#include <functional>

using namespace std::chrono_literals;

void refershForecast(std::map<std::string, int>& tempMap) {
  while (true) {
    for (auto& item: tempMap) {
      item.second++;
      std::cout << item.first << " ---> " << item.second << "\n";
    }
    std::this_thread::sleep_for(2000ms);
  }
}

int main() {
  // Dummy Data
  std::map<std::string, int> tempMap = {
    {"City A", 69}, {"City B", 13}, {"City C", 46}
  };

  std::thread refereshThread(refershForecast, std::ref(tempMap));
  refereshThread.join();

  return 0;
}