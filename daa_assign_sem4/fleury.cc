#include <iostream>
#include <vector>
#include <algorithm>

constexpr int V = 7;
std::vector<std::vector<int>> graph(V);

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void removeEdge(int u, int v) {
    graph[u].erase(std::find(graph[u].begin(), graph[u].end(), v));
    graph[v].erase(std::find(graph[v].begin(), graph[v].end(), u));
}

int dfsCount(int u, std::vector<bool>& visited) {
    visited[u] = true;
    int count = 1;
    for (int v : graph[u]) {
        if (!visited[v]) count += dfsCount(v, visited);
    }
    return count;
}

bool isValidNextEdge(int u, int v) {
    if (graph[u].size() == 1) return true;

    std::vector<bool> visited(V, false);
    int count1 = dfsCount(u, visited);

    removeEdge(u, v);
    visited.assign(V, false);
    int count2 = dfsCount(u, visited);
    addEdge(u, v);

    return count2 >= count1;
}

void fleury(int u) {
    for (int v : graph[u]) {
        if (isValidNextEdge(u, v)) {
            std::cout << char('A' + u) << " - " << char('A' + v) << "\n";
            removeEdge(u, v);
            fleury(v);
            break; // reset loop since graph[u] has changed
        }
    }
}

int main() {
    // Build the graph
    addEdge(0, 1); // A-B
    addEdge(0, 4); // A-E
    addEdge(0, 5); // A-F
    addEdge(0, 6); // A-G
    addEdge(1, 2); // B-C
    addEdge(1, 4); // B-E
    addEdge(1, 4); // B-E (again)
    addEdge(2, 3); // C-D
    addEdge(3, 4); // D-E

    // Find starting vertex
    int start = 0;
    int oddCount = 0;
    for (int i = 0; i < V; ++i) {
        if (graph[i].size() % 2 != 0) {
            ++oddCount;
            start = i;
        }
    }

    std::cout << "Fleury's Algorithm Output:\n";
    if (oddCount == 0 || oddCount == 2) {
        fleury(start);
    } else {
        std::cout << "Graph is not Eulerian.\n";
    }

    return 0;
}

