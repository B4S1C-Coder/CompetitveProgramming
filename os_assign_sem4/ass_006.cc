#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <queue>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int startTime;
    int priority;

    Process(int i, int at, int bt, int prio = 0) {
        id = i;
        arrivalTime = at;
        burstTime = bt;
        remainingTime = bt;
        completionTime = 0;
        waitingTime = 0;
        startTime = -1;
        priority = prio;
    }
};

void nonPreemptivePriority(std::vector<Process>& processes) {
    int n = processes.size();
    std::vector<bool> completed(n, false);
    std::vector<int> executionSeq;
    int currentTime = 0;
    int completedCount = 0;

    while (completedCount < n) {
        int highestPriority = INT_MAX;
        int selectedProcess = -1;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && 
                processes[i].arrivalTime <= currentTime && 
                processes[i].priority < highestPriority) {
                highestPriority = processes[i].priority;
                selectedProcess = i;
            }
        }

        if (selectedProcess == -1) {
            currentTime++;
            continue;
        }

        // Process found, execute it
        processes[selectedProcess].startTime = currentTime;
        currentTime += processes[selectedProcess].burstTime;
        processes[selectedProcess].completionTime = currentTime;
        processes[selectedProcess].waitingTime = 
            processes[selectedProcess].startTime - 
            processes[selectedProcess].arrivalTime;
        
        completed[selectedProcess] = true;
        completedCount++;
        executionSeq.push_back(processes[selectedProcess].id);
    }

    std::cout << "\nExecution Sequence: ";
    for (int id : executionSeq) {
        std::cout << "P" << id << " ";
    }
}

// Preemptive Priority Scheduling
void preemptivePriority(std::vector<Process>& processes) {
    int n = processes.size();
    std::vector<int> executionSeq;
    int currentTime = 0;
    int completedCount = 0;
    int prevProcess = -1;

    std::vector<int> remainingTime(n);
    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].burstTime;
    }

    while (completedCount < n) {
        int highestPriority = INT_MAX;
        int selectedProcess = -1;

        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0 && 
                processes[i].arrivalTime <= currentTime && 
                processes[i].priority < highestPriority) {
                highestPriority = processes[i].priority;
                selectedProcess = i;
            }
        }

        if (selectedProcess == -1) {
            currentTime++;
            continue;
        }

        if (processes[selectedProcess].startTime == -1) {
            processes[selectedProcess].startTime = currentTime;
        }

        remainingTime[selectedProcess]--;
        currentTime++;

        if (prevProcess != processes[selectedProcess].id) {
            executionSeq.push_back(processes[selectedProcess].id);
            prevProcess = processes[selectedProcess].id;
        }

        if (remainingTime[selectedProcess] == 0) {
            completedCount++;
            processes[selectedProcess].completionTime = currentTime;
            processes[selectedProcess].waitingTime = 
                (processes[selectedProcess].completionTime - 
                 processes[selectedProcess].arrivalTime - 
                 processes[selectedProcess].burstTime);
        }
    }

    std::cout << "\nExecution Sequence: ";
    for (int id : executionSeq) {
        std::cout << "P" << id << " ";
    }
}

// Round Robin Scheduling
void roundRobin(std::vector<Process>& processes, int timeQuantum) {
    int n = processes.size();
    std::vector<int> executionSeq;
    int currentTime = 0;
    int completedCount = 0;
    
    // Sort processes by arrival time
    std::sort(processes.begin(), processes.end(), 
        [](const Process& a, const Process& b) {
            return a.arrivalTime < b.arrivalTime;
        });
    
    std::vector<int> remainingTime(n);
    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].burstTime;
    }
    
    std::queue<int> readyQueue;
    int idx = 0;
    
    // Add first process to queue
    if (n > 0) {
        readyQueue.push(0);
        idx = 1;
    }

    while (completedCount < n) {
        // If queue is empty but there are still processes to arrive
        if (readyQueue.empty()) {
            if (idx < n) {
                currentTime = processes[idx].arrivalTime;
                readyQueue.push(idx);
                idx++;
            }
            continue;
        }
        
        int processIdx = readyQueue.front();
        readyQueue.pop();
        
        // Record start time if first execution
        if (processes[processIdx].startTime == -1) {
            processes[processIdx].startTime = currentTime;
        }
        
        // Add to execution sequence
        executionSeq.push_back(processes[processIdx].id);
        
        // Calculate execution time for this time quantum
        int executionTime = std::min(timeQuantum, remainingTime[processIdx]);
        remainingTime[processIdx] -= executionTime;
        currentTime += executionTime;
        
        // Check if new processes arrived during execution
        while (idx < n && processes[idx].arrivalTime <= currentTime) {
            readyQueue.push(idx);
            idx++;
        }
        
        // If process is not complete, add back to queue
        if (remainingTime[processIdx] > 0) {
            readyQueue.push(processIdx);
        } else {
            // Process completed
            completedCount++;
            processes[processIdx].completionTime = currentTime;
            processes[processIdx].waitingTime = 
                processes[processIdx].completionTime - 
                processes[processIdx].arrivalTime - 
                processes[processIdx].burstTime;
        }
    }

    std::cout << "\nExecution Sequence: ";
    for (int id : executionSeq) {
        std::cout << "P" << id << " ";
    }
}

int main() {
    int n;
    std::cout << "Enter number of processes> ";
    std::cin >> n;

    std::vector<Process> processes;

    for (int i = 0; i < n; i++) {
        int at, bt, prio;
        std::cout << "Process - " << i + 1 << "\n";
        std::cout << "Arrival time> ";
        std::cin >> at;
        std::cout << "Burst time> ";
        std::cin >> bt;
        std::cout << "Priority (lower number means higher priority)> ";
        std::cin >> prio;

        processes.push_back(Process(i + 1, at, bt, prio));
    }

    while (true) {
        std::cout << "\nChoose Algorithm:\n";
        std::cout << "1) Non-preemptive Priority\n";
        std::cout << "2) Preemptive Priority\n";
        std::cout << "3) Round Robin\n";
        std::cout << "4) Exit\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 7) { break; }

        std::vector<Process> temp = processes;

        switch (choice) {
            case 1:
                nonPreemptivePriority(temp);
                break;
            case 2:
                preemptivePriority(temp);
                break;
            case 3:
                int timeQuantum;
                std::cout << "Enter time quantum> ";
                std::cin >> timeQuantum;
                roundRobin(temp, timeQuantum);
                break;
            case 4:
                break;
            default:
                std::cout << "\nInvalid choice.\n";
                continue;
        }

        std::cout << "\nWaiting Time\n";
        double totalWaitTime = 0;

        for (const auto& p: temp) {
            std::cout << "P" << p.id << "\t" << p.waitingTime << "\n";
            totalWaitTime += p.waitingTime;
        }

        std::cout << "\nAverage wait time: " << totalWaitTime/n << "\n";
    }

    return 0;
}
