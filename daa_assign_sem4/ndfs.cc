#include <vector>
#include <stack>
#include <iostream>

void depthFirstSearch(
  const std::vector<std::vector<int>>& adjList,
  const int& root,
  const int& target
)
{
  std::stack<int> dfsStack;
  int visited  [adjList.size() + 1] = {0};
  int explored [adjList.size() + 1] = {0};
  
  dfsStack.push(root);

  while(!dfsStack.empty()) {
    int node = dfsStack.top();
    dfsStack.pop();

    if (!visited[node]) {
      std::cout << node << " ";
      visited[node]++;
    }

    if (adjList[node].size() == 0) {
      explored[node]++;
      continue;
    }

    // Extract 1st unvisited neighbour
    int unvisitedNeighbour = -1;
    for (const int& i: adjList[node]) {
      if (!visited[i]) {
        unvisitedNeighbour = i;
        break;
      }
    }
    
    if (unvisitedNeighbour == -1) {
      explored[node]++;
    } else {
      dfsStack.push(node);
      dfsStack.push(unvisitedNeighbour);
    }
  }
} 

int main() {
  std::vector<std::vector<int>> adjList(10); // assuming nodes are 1-indexed up to 9

  adjList[1] = {2, 4, 3};
  adjList[2] = {5, 6};
  adjList[3] = {7};
  adjList[4] = {8, 9};
  adjList[5] = {};
  adjList[6] = {};
  adjList[7] = {};
  adjList[8] = {};
  adjList[9] = {};
  
  depthFirstSearch(adjList, 1, 7);
  std::cout << "\n";

  return 0;
}
