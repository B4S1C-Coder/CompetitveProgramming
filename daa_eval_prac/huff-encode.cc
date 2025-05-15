#include <queue>
#include <unordered_map>
#include <vector>

struct {
  char ch;
  int freq;
  Node* left;
  Node* right;

  Node (int f, Node* l=nullptr, Node* r=nullptr, char c='\0')
    : freq(f), ch(c), left(l), right(r) {}
} Node;

auto cmp = [](const Node& n1, const Node& n2) { return n1.freq > n2.freq; };

void constructHuffmanTree(std::priority_queue<Node*, std::vector<Node*>, decltype(cmp)>& pq) {
  while (pq.size() > 1) {
    Node* l = pq.top();
    pq.pop();

    Node* r = pq.top();
    pq.pop();

    pq.push(new Node(l->freq + r->freq, l, r));
  }
}

