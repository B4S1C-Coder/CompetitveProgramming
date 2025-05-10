#include <iostream>
#include <vector>

constexpr int N = 3;
int G[N][N] = {
    {0, 1, 1},
    {1, 0, 1},
    {1, 1, 0}
};

void findHamiltonian(int k, std::vector<int>& x, bool& foundCycle, bool& foundPath);

void nextValue(int k, std::vector<int>& x) {
    do {
        x[k] = (x[k] + 1) % (N + 1);
        if (x[k] == 0) return;

        bool isConnected = G[x[k - 1] - 1][x[k] - 1] != 0;
        bool isDistinct = true;

        for (int j = 0; j < k; ++j) {
            if (x[j] == x[k]) {
                isDistinct = false;
                break;
            }
        }

        if (isConnected && isDistinct) {
            if (k < N - 1 || (k == N - 1 && G[x[k] - 1][x[0] - 1] != 0)) return;
        }
    } while (true);
}

void findHamiltonian(int k, std::vector<int>& x, bool& foundCycle, bool& foundPath) {
    while (true) {
        nextValue(k, x);
        if (x[k] == 0) return;

        if (k == N - 1) {
            foundPath = true;
            if (G[x[k] - 1][x[0] - 1]) foundCycle = true;

            std::cout << "Hamiltonian ";
            if (G[x[k] - 1][x[0] - 1]) std::cout << "Cycle: ";
            else std::cout << "Path: ";
            for (int val : x) std::cout << val << " ";
            std::cout << std::endl;
        } else {
            findHamiltonian(k + 1, x, foundCycle, foundPath);
        }
    }
}

int main() {
    std::vector<int> x(N, 0);
    x[0] = 1;

    bool foundCycle = false, foundPath = false;
    findHamiltonian(1, x, foundCycle, foundPath);

    std::cout << "\nResult: ";
    if (foundCycle) std::cout << "Hamiltonian Cycle exists.\n";
    else if (foundPath) std::cout << "Hamiltonian Path exists, but no cycle.\n";
    else std::cout << "No Hamiltonian Path or Cycle.\n";

    return 0;
}

