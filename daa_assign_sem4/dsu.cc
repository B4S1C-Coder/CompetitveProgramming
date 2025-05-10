#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DSU {
    vector<int> parent, size;

public:
    DSU(int n) : parent(n + 1), size(n + 1, 1) {
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }

    int find(int x) {
        return parent[x] = (parent[x] == x ? x : find(parent[x]));
    }

    void unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr != yr) {
            parent[yr] = xr;
            size[xr] += size[yr];
        }
    }

    unordered_map<int, int> getGroups(int n) {
        unordered_map<int, int> groupSizes;
        for (int i = 1; i <= n; ++i)
            groupSizes[find(i)]++;
        return groupSizes;
    }
};

int main() {
    int N = 5;
    vector<pair<int, int>> friendships = {{1, 2}, {5, 4}, {5, 1}};
    DSU dsu(N);

    for (auto [u, v] : friendships)
        dsu.unite(u, v);

    auto groups = dsu.getGroups(N);

    cout << "Number of groups: " << groups.size() << "\n";
    cout << "Sizes: ";
    for (auto& [_, size] : groups) cout << size << " ";
    cout << "\n";
}
