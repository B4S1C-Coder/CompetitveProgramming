#include <iostream>
#include <vector>
#include <queue>

std::vector<int> kahn(int n, const std::vector<std::vector<int>>& adj) {
  std::vector<int> indegree(n + 1, 0);
  std::vector<int> topoOrder;
  std::queue<int> q;

  // calculate indegree
  for (int i = 1; i <= n; i++) {
    for (int v: adj[i]) {
      indegree[v]++;
    }
  }

  // get the nodes of indegree = 0
  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topoOrder.push_back(u);

    for (int v: adj[u]) {
      if (--indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  if (topoOrder.size() != n) {
    std::cout << "Possible cycles in graph. Topological Sort not possible.\n";
    return {};
  }

  return topoOrder;
}

int main() {
  std::vector<std::vector<int>> adj = {
    {},         // 0 (not used)
    {4, 7, 5},  // 1 → 4, 7, 5
    {3, 5, 6},  // 2 → 3, 5, 6
    {4, 5},     // 3 → 4, 5
    {5},        // 4 → 5
    {6, 7},     // 5 → 6, 7
    {7},        // 6 → 7
    {}         // 7 → None
  };

  std::vector<int> topoligocalSurt = kahn(7, adj);

  for (int node: topoligocalSurt) {
    std::cout << "v" << node << " ";
  }

  std::cout << "\n";

  return 0;
}
