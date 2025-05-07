#include <vector>
#include <iostream>

#define NUM_NODES 14

std::vector<int> ccnum(NUM_NODES, 0);
std::vector<int> visited(NUM_NODES, 0);
std::vector<int> pre(NUM_NODES, 0);
std::vector<int> post(NUM_NODES, 0);

void previsit(int v, int cc, int& clock) {
  ::ccnum[v] = cc;
  ::pre[v] = clock;
  clock++;
}

void postvisit(int v, int& clock) {
  ::post[v] = clock;
  clock++;
}

void DFS(const std::vector<std::vector<int>>& graph, int v, int cc, int& clock) {
  visited[v] = 1;
  previsit(v, cc, clock);

  for (const int& w: graph[v]) {
    if (::visited[w] == 0) {
      DFS(graph, w, cc, clock);
    }
  }

  postvisit(v, clock);
}

void DFT(const std::vector<std::vector<int>>& graph) {
  int cc = 0, clock = 1;
  
  for (int i = 1; i < NUM_NODES; i++) {
    if (::visited[i] == 0) {
      cc++;
      DFS(graph, i, cc, clock);
    }
  }

  for (int i = 1; i < NUM_NODES; i++) {
    std::cout << i << " --> " << pre[i] << " , " << post[i] << "\n";
  }

  std::cout << "Number of connected components: " << cc << "\n";
}

int main() {
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

  DFT(adj);

  return 0;
}
