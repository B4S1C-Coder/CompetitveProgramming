#include <iostream>
#include <vector>

using namespace std;

struct Process {
    int id;
    vector<int> allocated;
    vector<int> max;
    vector<int> need;
    bool isOutOfProblemMatrix;

    Process(int id, vector<int> alloc, vector<int> maxRes)
        : id(id), allocated(alloc), max(maxRes), isOutOfProblemMatrix(false) {
        need.resize(maxRes.size());
        for (size_t i = 0; i < maxRes.size(); i++) {
            need[i] = maxRes[i] - alloc[i];
        }
    }
};

bool is_need_satisfied(Process &p, vector<int> &resAvailableMatrix) {
    for (size_t i = 0; i < resAvailableMatrix.size(); i++) {
        if (p.need[i] > resAvailableMatrix[i]) {
            return false;
        }
    }
    return true;
}

bool proceed_banker_algorithm(vector<int> &resAvailableMatrix, vector<Process> &problemMatrix) {
    for (auto &proc : problemMatrix) {
        if (!proc.isOutOfProblemMatrix && is_need_satisfied(proc, resAvailableMatrix)) {
            for (size_t i = 0; i < resAvailableMatrix.size(); i++) {
                resAvailableMatrix[i] += proc.allocated[i];
            }
            proc.isOutOfProblemMatrix = true;
            cout << "P" << proc.id << " ";
            return true;
        }
    }
    return false;
}

bool is_system_safe(vector<Process> &problemMatrix) {
    for (auto &proc : problemMatrix) {
        if (!proc.isOutOfProblemMatrix) {
            return false;
        }
    }
    return true;
}

void run_case(vector<int> resAvailableMatrix, vector<Process> problemMatrix) {
    cout << "Safe Sequence: ";
    while (proceed_banker_algorithm(resAvailableMatrix, problemMatrix));

    if (is_system_safe(problemMatrix)) {
        cout << "\nSystem is in a Safe State.\n";
    } else {
        cout << "\nNo Safe Sequence Exists!\n";
    }
}

int main() {
    cout << "Running Safe Sequence Case...\n";
    vector<int> resAvailableMatrix1 = {3, 3, 2, 2};
    vector<Process> problemMatrix1 = {
        Process(0, {0, 0, 2, 2}, {1, 2, 2, 3}),
        Process(1, {1, 2, 3, 3}, {0, 1, 3, 3}),
        Process(2, {3, 3, 3, 3}, {3, 3, 3, 3})
    };
    run_case(resAvailableMatrix1, problemMatrix1);

    cout << "\nRunning No Safe Sequence Case...\n";
    vector<int> resAvailableMatrix2 = {1, 0, 2, 1};
    vector<Process> problemMatrix2 = {
        Process(0, {1, 1, 1, 2}, {3, 2, 2, 2}),
        Process(1, {0, 0, 1, 1}, {1, 1, 3, 2}),
        Process(2, {3, 2, 2, 2}, {3, 3, 3, 3})
    };
    run_case(resAvailableMatrix2, problemMatrix2);

    return 0;
}

