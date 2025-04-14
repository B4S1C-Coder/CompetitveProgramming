#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

struct Block {
    int start;
    int size;
    bool allocated;
};

std::vector<Block> memory;

void initializeMemory(int totalSize) {
    memory.clear();
    memory.push_back({0, totalSize, false});
}

void displayMemory() {
    std::cout << "\nMemory State:\n";
    for (const auto& block : memory) {
        std::cout << "[" << block.start << " - " << block.start + block.size - 1 << "] "
                  << (block.allocated ? "Allocated" : "Free") << "\n";
    }
}

bool allocateMemory(int reqSize, int strategy) {
    int index = -1;
    if (strategy == 1) { // First Fit
        for (int i = 0; i < memory.size(); ++i) {
            if (!memory[i].allocated && memory[i].size >= reqSize) {
                index = i;
                break;
            }
        }
    } else if (strategy == 2) { // Best Fit
        int minFit = INT32_MAX;
        for (int i = 0; i < memory.size(); ++i) {
            if (!memory[i].allocated && memory[i].size >= reqSize && memory[i].size < minFit) {
                minFit = memory[i].size;
                index = i;
            }
        }
    } else if (strategy == 3) { // Worst Fit
        int maxFit = -1;
        for (int i = 0; i < memory.size(); ++i) {
            if (!memory[i].allocated && memory[i].size >= reqSize && memory[i].size > maxFit) {
                maxFit = memory[i].size;
                index = i;
            }
        }
    }

    if (index == -1) {
        std::cout << "Allocation failed: No suitable block found.\n";
        return false;
    }

    Block& blk = memory[index];
    if (blk.size == reqSize) {
        blk.allocated = true;
    } else {
        Block allocatedBlock = {blk.start, reqSize, true};
        Block remainingBlock = {blk.start + reqSize, blk.size - reqSize, false};
        memory[index] = allocatedBlock;
        memory.insert(memory.begin() + index + 1, remainingBlock);
    }
    std::cout << "Allocation successful.\n";
    return true;
}

int main() {
    int totalSize;
    std::cout << "Enter total memory size: ";
    std::cin >> totalSize;

    initializeMemory(totalSize);

    while (true) {
        std::cout << "\nMenu:\n"
                  << "1. First Fit\n"
                  << "2. Best Fit\n"
                  << "3. Worst Fit\n"
                  << "4. Exit\n"
                  << "Choose an option: ";
        int choice;
        std::cin >> choice;

        if (choice == 4) break;

        int reqSize;
        std::cout << "Enter size to allocate: ";
        std::cin >> reqSize;

        allocateMemory(reqSize, choice);
        displayMemory();
    }

    return 0;
}

