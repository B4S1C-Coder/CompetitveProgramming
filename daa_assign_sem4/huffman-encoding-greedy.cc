#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>

struct Node {
  char ch;
  int freq;
  Node* left;
  Node* right;

  Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
  Node(int f, Node* l, Node* r) : ch('\0'), freq(f), left(l), right(r) {}
};

struct Cmp {
  bool operator()(Node* a, Node* b) { return a->freq > b->freq; }
};

void makeCode(Node* node, const std::string& code, std::unordered_map<std::string, std::string>& huffCodes) {
  if (!node) return;
  if (!node->left && !node->right) {
    huffCodes[std::string(1, node->ch)] = code;
  }

  makeCode(node->left, code + "0", huffCodes);
  makeCode(node->right, code + "1", huffCodes);
}

std::unordered_map<std::string, std::string> huffmanEncode(const std::unordered_map<char, int>& freqMap) {
  std::priority_queue<Node*, std::vector<Node*>, Cmp> minHeap;

  for (const auto& entry : freqMap) {
    minHeap.push(new Node(entry.first, entry.second));
  }

  while (minHeap.size() > 1) {
    auto x = minHeap.top();
    minHeap.pop();

    auto y = minHeap.top();
    minHeap.pop();

    auto z = new Node(x->freq + y->freq, x, y);
    minHeap.push(z);
  }

  std::unordered_map<std::string, std::string> huffmanCodes;
  makeCode(minHeap.top(), "", huffmanCodes);
  return huffmanCodes;
}

int main() {
  std::unordered_map<char, int> frequencyMap = {
    {'a', 45}, {'b', 13}, {'c', 12}, {'d', 16}, {'e', 9}, {'f', 5}
  };

  std::unordered_map<std::string, std::string> huffmanCodes = huffmanEncode(frequencyMap);

  for (const auto& pair: huffmanCodes) {
    std::cout << pair.first << " : " << pair.second << "\n";
  }

  return 0;
}
