#include <vector>
#include <iostream>

int NUM_NODES = 14;

std::vector<int> visited(NUM_NODES, 0);
std::vector<int> pre(NUM_NODES, 0);
std::vector<int> post(NUM_NODES, 0);

void previsit(int v, int& clock) {
  ::pre[v] = clock;
  clock++;
}

void postvisit(int v, int& clock) {
  ::post[v] = clock;
  clock++;
}

void DFS(const std::vector<std::vector<int>>& graph, int v, bool& cycleFound) {
  int clock = 1;
  ::visited[v] = 1;
  
  cycleFound = false;

  previsit(v, clock);

  for (const int& w: graph[v]) {
    if (::visited[w] == 0) {
      DFS(graph, w, cycleFound);
    } else if (::post[w] != 0) { continue; }
    else {
      cycleFound = true;
    }
  }

  postvisit(v, clock);
}

int main() {
  
  std::vector<std::vector<int>> adj_cycle = {
    {},         // index 0 (unused)
    {3, 6},     // 1 → C, F
    {1, 5},     // 2 → A, E
    {4},        // 3 → D
    {8},        // 4 → H
    {6, 7},     // 5 → F, G
    {7},        // 6 → G
    {8},        // 7 → H
    {5}         // 8 → E
  };
  std::vector<std::vector<int>> adj(NUM_NODES); 

  adj[1] = {2, 3};
  adj[2] = {1, 3, 4, 5};
  adj[3] = {1, 2, 5, 7, 8};
  adj[4] = {2, 5};
  adj[5] = {2, 3, 4, 6};
  adj[6] = {5};
  adj[7] = {3, 8};
  adj[8] = {3, 7};
  adj[9] = {10};
  adj[10] = {9};
  adj[11] = {12};
  adj[12] = {11, 13};
  adj[13] = {12};
  
  bool cycleFound;

  DFS(adj_cycle, 1, cycleFound);
  
  if (cycleFound) {
    std::cout << "Cycle found.\n";
  } else {
    std::cout << "Cycle not found.\n";
  }
  ::visited.clear();
  ::pre.clear();
  ::post.clear();

  DFS(adj, 1, cycleFound);
  if (cycleFound) {
    std::cout << "Cycle found.\n";
  } else {
    std::cout << "Cycle not found.\n";
  }
  return 0;
}
