#include <iostream>
#include <vector>

class Data {
  std::vector<int> nums;
  int currentLargest;

  void largest() {
    if (nums.size() == 0) { return; }
    int largest = nums[0];

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > largest) { largest = nums[i]; }
    }

    currentLargest = largest;
  }

public:
  void getData(int numElems) {
    int temp;
    for (int i = 0; i < numElems; i++) {
      std::cout << "Element (" << i + 1 << " of " << numElems << ")> ";
      std::cin >> temp;
      nums.push_back(temp);
    }

    largest();
  }

  void display() {
    std::cout << "Largest Number: " << currentLargest << "\n";
  }

  void insert(int val) {
    nums.push_back(val);
    if (val > currentLargest) {
      currentLargest = val;
    }
  }
};

int main() {
  Data d;
  d.getData(5);
  d.display();
  d.insert(69000);
  d.display();
  return 0;
}
