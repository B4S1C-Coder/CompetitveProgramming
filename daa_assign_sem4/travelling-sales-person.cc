// Travelling Salesman Problem using LCBB and FIFOBB
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

const int INF = std::numeric_limits<int>::max();

struct Node {
    std::vector<int> path;
    int level, cost, bound;
    std::vector<bool> visited;

    bool operator<(const Node& other) const {
        return bound > other.bound; // for LCBB priority queue
    }
};

int calculateBound(const Node& node, const std::vector<std::vector<int>>& graph) {
    int bound = node.cost;
    int n = graph.size();

    for (int i = 0; i < n; ++i) {
        if (!node.visited[i]) {
            int minEdge = INF;
            for (int j = 0; j < n; ++j) {
                if (i != j && !node.visited[j]) {
                    minEdge = std::min(minEdge, graph[i][j]);
                }
            }
            bound += (minEdge == INF ? 0 : minEdge);
        }
    }
    return bound;
}

void solveTSP_LCBB(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::priority_queue<Node> pq;

    Node root = {{0}, 0, 0, 0, std::vector<bool>(n, false)};
    root.visited[0] = true;
    root.bound = calculateBound(root, graph);
    pq.push(root);

    int minCost = INF;
    std::vector<int> bestPath;

    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (curr.bound >= minCost) continue;
        if (curr.level == n - 1) {
            int last = curr.path.back();
            if (graph[last][0] != INF) {
                int cost = curr.cost + graph[last][0];
                if (cost < minCost) {
                    minCost = cost;
                    bestPath = curr.path;
                    bestPath.push_back(0);
                }
            }
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (!curr.visited[i] && graph[curr.path.back()][i] != INF) {
                Node child = curr;
                child.path.push_back(i);
                child.level++;
                child.cost += graph[curr.path[child.level - 1]][i];
                child.visited[i] = true;
                child.bound = calculateBound(child, graph);

                if (child.bound < minCost) pq.push(child);
            }
        }
    }

    std::cout << "LCBB TSP cost: " << minCost << "\nPath: ";
    for (int city : bestPath) std::cout << city << " ";
    std::cout << "\n";
}

void solveTSP_FIFOBB(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::queue<Node> q;

    Node root = {{0}, 0, 0, 0, std::vector<bool>(n, false)};
    root.visited[0] = true;
    root.bound = calculateBound(root, graph);
    q.push(root);

    int minCost = INF;
    std::vector<int> bestPath;

    while (!q.empty()) {
        Node curr = q.front(); q.pop();

        if (curr.bound >= minCost) continue;
        if (curr.level == n - 1) {
            int last = curr.path.back();
            if (graph[last][0] != INF) {
                int cost = curr.cost + graph[last][0];
                if (cost < minCost) {
                    minCost = cost;
                    bestPath = curr.path;
                    bestPath.push_back(0);
                }
            }
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (!curr.visited[i] && graph[curr.path.back()][i] != INF) {
                Node child = curr;
                child.path.push_back(i);
                child.level++;
                child.cost += graph[curr.path[child.level - 1]][i];
                child.visited[i] = true;
                child.bound = calculateBound(child, graph);

                if (child.bound < minCost) q.push(child);
            }
        }
    }

    std::cout << "FIFOBB TSP cost: " << minCost << "\nPath: ";
    for (int city : bestPath) std::cout << city << " ";
    std::cout << "\n";
}

int main() {
    std::vector<std::vector<int>> graph = {
        {INF, 20, 30, 10, 11},
        {15, INF, 16, 4 , 2 },
        {3 , 5 , INF, 2 , 4 },
        {19, 6 , 18, INF, 3 },
        {16, 4 , 7 , 16 , INF }
    };

    solveTSP_LCBB(graph);
    solveTSP_FIFOBB(graph);
    return 0;
}

