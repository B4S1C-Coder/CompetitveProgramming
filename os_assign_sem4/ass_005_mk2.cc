#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int startTime;

    Process(int i, int at, int bt) {
        id = i;
        arrivalTime = at;
        burstTime = bt;
        remainingTime = bt;
        completionTime = 0;
        waitingTime = 0;
        startTime = -1;
    }
};

void FCFS(std::vector<Process>& processes) {
    std::sort(processes.begin(), processes.end(), 
        [](const Process& a, const Process& b) {
            return a.arrivalTime < b.arrivalTime;
        });

    int currentTime = 0;
    std::vector<int> executionSeq;

    for (auto& p : processes) {
        if (currentTime < p.arrivalTime) {
            currentTime = p.arrivalTime;
        }
        
        p.startTime = currentTime;
        executionSeq.push_back(p.id);
        currentTime += p.burstTime;
        p.completionTime = currentTime;
        p.waitingTime = p.startTime - p.arrivalTime;
    }

    std::cout << "\nExecution Sequence: ";
    for (int id : executionSeq) {
        std::cout << "P" << id << " ";
    }
}

void nonPreemptiveSJF(std::vector<Process>& processes) {
    int n = processes.size();
    std::vector<bool> completed(n, false);
    std::vector<int> executionSeq;
    int currentTime = 0;
    int completedCount = 0;

    while (completedCount < n) {
        int shortestBT = INT_MAX;
        int selectedProcess = -1;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && 
                processes[i].arrivalTime <= currentTime && 
                processes[i].burstTime < shortestBT) {
                shortestBT = processes[i].burstTime;
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

void preemptiveSJF(std::vector<Process>& processes) {
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
        int shortestRT = INT_MAX;
        int selectedProcess = -1;

        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0 && 
                processes[i].arrivalTime <= currentTime && 
                remainingTime[i] < shortestRT) {
                shortestRT = remainingTime[i];
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

int main() {
  int n;
  std::cout << "Enter number of processes> ";
  std::cin >> n;

  std::vector<Process> processes;

  for (int i = 0; i < n; i++) {
    int at, bt;
    std::cout << "Process - " << i + 1 << "\n";
    std::cout << "Arrival time> ";
    std::cin >> at;
    std::cout << "Burst time> ";
    std::cin >> bt;

    processes.push_back(Process(i + 1, at, bt));
  }

  while (true) {
    std::cout << "\nChoose Algorithm:\n";
    std::cout << "1) FCFS\n2)Non-preemptive SJF\n3)Preemptive SJF\n4) Anything else to quit\n";
    std::cout << "Choice: ";

    int choice;
    std::cin >> choice;

    if (choice == 4) { break; }

    std::vector<Process> temp = processes;

    switch (choice) {
      case 1:
        FCFS(temp);
        break;
      case 2:
        nonPreemptiveSJF(temp);
        break;
      case 3:
        preemptiveSJF(temp);
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
