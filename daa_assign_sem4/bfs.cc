#include <unordered_map>
#include <vector>
#include <iostream>
#include <queue>

struct Node {
  int   key;    // It is assumed that this is unique
  Node* next;
  Node  (int d, Node* n=nullptr): key(d), next(n) {}
};

std::vector<int> breadthFirstSearch(const std::unordered_map<int, Node*>& adjList, const int& root, const int& target) {
  std::queue<int> BFSQueue;
  BFSQueue.push(root);

  std::vector<int> traversal;
  traversal.push_back(root);
  bool found = false;

  while (!BFSQueue.empty() ) {
    Node* node = adjList.at(BFSQueue.front());
    BFSQueue.pop();
    
    if (!node) continue;

    while (node != nullptr) {
      traversal.push_back(node->key);
      BFSQueue.push(node->key);

      if (node->key == target) {
        std::cout << "Element found\n";
        found = true;
        break;
      }
      node = node->next;
    }

    if (found) break;
  }

  return traversal;
}

template<typename T>
void printVector(const std::vector<T>& _vec) {
  for (const T& x: _vec) { std::cout << x << " "; }
  std::cout << "\n--------------\n";
}

int main() {

  // Making nodes and linked lists
  Node n1(1), n2(2), n3(3), n4(4), n5(5);
  n2.next = &n3;
  n4.next = &n5;
  
  std::unordered_map<int, Node*> adjList = {
    {1, &n2}, {2, &n4}, {3, nullptr}, {4, nullptr}, {5, nullptr}
  };

  std::vector<int> BFSTraversal = breadthFirstSearch(adjList, 1, 5);
  printVector(BFSTraversal);

  return 0;
}
