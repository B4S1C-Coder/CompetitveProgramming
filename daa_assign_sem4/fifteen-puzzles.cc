#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#define N 4

struct Node {
  std::vector<std::vector<int>> mat;
  int x, y;
  int g, h;
  std::string path;

  bool operator>(const Node& o) const {
    return g + h > o.g + o.h;
  }
};

std::vector<std::vector<int>> goal = {
  {1 , 2 , 3 , 4 },
  {5 , 6 , 7 , 8 },
  {9 , 10, 11, 12},
  {13, 14, 15, 0}
};

// Directions
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char dir[] = {'L', 'R', 'U', 'D'};

int heuristic(const std::vector<std::vector<int>>& mat) {
  int d = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (mat[i][j] && mat[i][j] != 0) {
        int val = mat[i][j] - 1;
        d += abs(i - val / N) + abs(j - val % N);
      }
    }
  }
  return d;
}

std::string serialize(const std::vector<std::vector<int>>& mat) {
  std::string s;
  for (auto& row: mat) {
    for (int x: row) {
      s += std::to_string(x) + ",";
    }
  }
  return s;
}

void solve(std::vector<std::vector<int>> start) {
  int sx, sy;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (start[i][j] == 0) {
        sx = i;
        sy = j;
      }
    }
  }

  std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
  std::unordered_set<std::string> visited;

  pq.push({start, sx, sy, 0, heuristic(start), ""});
  visited.insert(serialize(start));

  while (!pq.empty()) {
    auto node = pq.top(); pq.pop();

    if (node.mat == goal) {
      std::cout << "Solved in " << node.g << " moves\nPath: " << node.path << "\n";
      return;
    }

    for (int i = 0; i < 4; i++) {
      int nx = node.x + dx[i];
      int ny = node.y + dy[i];
      if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

      auto newMat = node.mat;
      std::swap(newMat[node.x][node.y], newMat[nx][ny]);

      std::string key = serialize(newMat);
      if (visited.count(key)) continue;

      visited.insert(key);
      pq.push({newMat, nx, ny, node.g + 1, heuristic(newMat), node.path + dir[i]});
    }
  }

  std::cout << "No solution found\n";
}

int main() {
  std::vector<std::vector<int>> puzzle = {
    {12, 1, 10, 2},
    {7, 11, 4, 14},
    {5, 0, 9, 15},
    {8, 13, 6, 3}
  };

  solve(puzzle);
  return 0;
}
