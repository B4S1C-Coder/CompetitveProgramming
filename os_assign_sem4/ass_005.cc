#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Process {
  int id;
  int arrivalTime;
  int burstTime;
  int remainingTime;
  int completionTime;
  int waitingTime;

  Process(int i, int at, int bt) {
    id = i;
    arrivalTime = at;
    burstTime = bt;
    remainingTime = bt;
    completionTime = 0;
    waitingTime = 0;
  }
};

void FCFS(std::vector<Process>& processes) {
  // Sort based on arriving time
  std::sort(processes.begin(), processes.end(), [](const Process& a, const Process&b) {
    return a.arrivalTime < b.arrivalTime;
  });

  int currentTime = 0;
  std::vector<int> executionSeq;

  for (auto& p : processes) {
    if (currentTime < p.arrivalTime) {
      currentTime = p.arrivalTime;
    }

    executionSeq.push_back(p.id);
    p.waitingTime = currentTime - p.arrivalTime;
    currentTime += p.burstTime;
    p.completionTime = currentTime;
  }

  std::cout << "\nExecution Sequence: ";
  for (int id: executionSeq) {
    std::cout << "P" << id << " ";
  }
}

void nonPreemptiveSJF(std::vector<Process>& processes) {
  std::vector<Process> remaining = processes;
  std::vector<int> executionSeq;
  int currentTime = 0;

  while (!remaining.empty()) {
    std::vector<Process*> _available;

    for (auto& p : remaining) {
      if (p.arrivalTime <= currentTime) {
        _available.push_back(&p);
      }
    }

    if (_available.empty()) {
      currentTime++;
      continue;
    }

    // Process with shortest remaining time
    auto shortest = std::min_element(_available.begin(), _available.end(),
      [](Process* a, Process* b) {
      return a->burstTime < b->burstTime;
    });

    Process* currentProcess = *shortest;
    executionSeq.push_back(currentProcess->id);

    currentProcess->waitingTime = currentTime - currentProcess->arrivalTime;
    if (currentProcess->waitingTime < 0) {
      currentProcess->waitingTime = 0;
    }
    currentTime += currentProcess->burstTime;
    currentProcess->completionTime = currentTime;

    // Remove the current process from remaining
    remaining.erase(
      std::remove_if(remaining.begin(), remaining.end(), [currentProcess](const Process& p) {
        return p.id == currentProcess->id;
      }), remaining.end()
    );
  }

  for (int id: executionSeq) {
    std::cout << "P" << id << " ";
  }
}

void preemptiveSJF(std::vector<Process>& processes) {
  std::vector<Process> remaining = processes;
  std::vector<int> executionSeq;
  int currentTime = 0;
  int prevProcess = -1;

  while (true) {
    bool allCompleted = true;
    std::vector<Process*> _available;

    for (auto& p: remaining) {
      if (p.remainingTime > 0) {
        allCompleted = false;
        if (p.arrivalTime <= currentTime) {
          _available.push_back(&p);
        }
      }
    }

    if (allCompleted) {
      break;
    }

    if (_available.empty()) {
      currentTime++;
      continue;
    }

    // Process with shortest remaining time
    auto shortest = std::min_element(_available.begin(), _available.end(),
      [](Process* a, Process* b) { return a->remainingTime < b->remainingTime; }
    );

    Process* currentProcess = *shortest;

    if (prevProcess != currentProcess->id) {
      executionSeq.push_back(currentProcess->id);
      prevProcess = currentProcess->id;
    }

    currentProcess->remainingTime--;
    currentTime++;

    if (currentProcess->remainingTime == 0) {
      currentProcess->completionTime = currentTime;
      currentProcess->waitingTime = currentProcess->completionTime - currentProcess->arrivalTime - currentProcess->burstTime;
    }

    for (auto& p: processes) {
      p.waitingTime = p.completionTime - p.arrivalTime - p.burstTime;
      if (p.waitingTime < 0) {
        p.waitingTime = 0;
      }
    }
  }

  std::cout << "\nExecution Sequence: ";
  for (int id: executionSeq) {
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
