#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <utility>
#include <iostream>

struct Node {
  char ch;
  int freq;
  Node* left;
  Node* right;
  bool isVisited;

  Node (int f, Node* l=nullptr, Node* r=nullptr, char c='\0')
    : freq(f), ch(c), left(l), right(r), isVisited(false) {}
};

std::unordered_map<char, std::string> driver(const std::string& msg) {
  std::unordered_map<char, int> freqMap;
  for (const char& c: msg) freqMap[c]++;

  auto cmp = [](Node* n1, Node* n2) { return n1->freq > n2->freq; };
  std::priority_queue<Node*, std::vector<Node*>, decltype(cmp)> pq(cmp);

  for (const auto& pair: freqMap) pq.push(new Node(pair.second, nullptr, nullptr, pair.first));

  while (pq.size() > 1) {
    Node* l = pq.top();
    pq.pop();

    Node* r = pq.top();
    pq.pop();

    Node* n = new Node(l->freq + r->freq, l, r);
    pq.push(n);
  }

  std::unordered_map<char, std::string> codes;
  std::stack<std::pair<Node*, std::string>> stk;

  stk.push({pq.top(), ""});
  std::string code = "";

  while (!stk.empty()) {
    auto [cur, path] = stk.top();
    stk.pop();

    if (!cur) continue;
    
    // leaf node
    if(!cur->left && !cur->right) {
      codes[cur->ch] = path;
      continue;
    }

    stk.push({cur->right, path + "1"});
    stk.push({cur->left, path + "0"});
  }
  
  return codes;
}

int main() {
  std::string message;
  std::cout << "Enter message> ";
  std::getline(std::cin, message);

  auto huffmanEncondingScheme = driver(message);
  
  std::cout << "HUFFMAN ENCODING SCHEME\n------------------\n";

  for (const auto& pair: huffmanEncondingScheme) {
    std::cout << pair.first << " <-> " << pair.second << "\n";
  }

  return 0;
}
