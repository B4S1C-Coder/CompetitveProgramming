// 0/1 Knapsack using LCBB and FIFOBB
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Item {
    int weight, profit;
    double ratio;
    Item(int w, int p) : weight(w), profit(p), ratio((double)p / w) {}
};

struct Node {
    int level, profit, weight;
    double bound;
};

bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

double bound(const Node& u, int n, int W, const std::vector<Item>& items) {
    if (u.weight >= W) return 0;
    double profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    while (j < n && totweight + items[j].weight <= W) {
        totweight += items[j].weight;
        profit_bound += items[j].profit;
        j++;
    }
    if (j < n)
        profit_bound += (W - totweight) * items[j].ratio;
    return profit_bound;
}

int knapsack_LCBB(int W, const std::vector<Item>& items) {
    int n = items.size();
    std::priority_queue<Node, std::vector<Node>,
        bool(*)(const Node&, const Node&)> Q([](const Node& a, const Node& b) {
        return a.bound < b.bound; // Max-Heap
    });

    Node u{}, v{};
    v.level = -1; v.profit = 0; v.weight = 0;
    v.bound = bound(v, n, W, items);
    Q.push(v);
    int maxProfit = 0;

    while (!Q.empty()) {
        v = Q.top(); Q.pop();
        if (v.bound <= maxProfit) continue;
        u.level = v.level + 1;
        u.weight = v.weight + items[u.level].weight;
        u.profit = v.profit + items[u.level].profit;
        if (u.weight <= W && u.profit > maxProfit)
            maxProfit = u.profit;
        u.bound = bound(u, n, W, items);
        if (u.bound > maxProfit)
            Q.push(u);

        u.weight = v.weight;
        u.profit = v.profit;
        u.bound = bound(u, n, W, items);
        if (u.bound > maxProfit)
            Q.push(u);
    }
    return maxProfit;
}

int knapsack_FIFOBB(int W, const std::vector<Item>& items) {
    int n = items.size();
    std::queue<Node> Q;
    Node u{}, v{};
    v.level = -1; v.profit = 0; v.weight = 0;
    v.bound = bound(v, n, W, items);
    Q.push(v);
    int maxProfit = 0;

    while (!Q.empty()) {
        v = Q.front(); Q.pop();
        if (v.level == n - 1) continue;
        u.level = v.level + 1;

        u.weight = v.weight + items[u.level].weight;
        u.profit = v.profit + items[u.level].profit;
        u.bound = bound(u, n, W, items);
        if (u.weight <= W && u.profit > maxProfit)
            maxProfit = u.profit;
        if (u.bound > maxProfit)
            Q.push(u);

        u.weight = v.weight;
        u.profit = v.profit;
        u.bound = bound(u, n, W, items);
        if (u.bound > maxProfit)
            Q.push(u);
    }
    return maxProfit;
}

int main() {
    std::vector<Item> items = {{2, 40}, {3, 50}, {4, 65}, {5, 35}, {1, 20}};
    int W = 10;
    std::sort(items.begin(), items.end(), cmp);

    std::cout << "Max Profit (LCBB): " << knapsack_LCBB(W, items) << '\n';
    std::cout << "Max Profit (FIFOBB): " << knapsack_FIFOBB(W, items) << '\n';
    return 0;
}

