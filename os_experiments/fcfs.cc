#include <iostream>
#include <vector>
#include <algorithm>

struct Process {
  int id;
  int at;
  int bt;
  int ct;
  int tat;
  int wt;

  void display() {
    std::cout << id << " | " << at << " | " << bt << " | " << ct << " | " << tat << " | " << wt << "\n";
  }
};

void FCFS(std::vector<Process>& procs) {
  std::sort(procs.begin(), procs.end(), [](Process& a, Process& b) {
    return a.at < b.at;
  });

  int curr = 0;

  std::cout << "id | at | bt | ct | tt | wt\n";
  std::cout << "---+----+----+----+----+---\n";

  for (Process& p: procs) {
    if (curr < p.at) { curr = p.at; }
    curr += p.bt;
    p.ct = curr;
    p.tat = p.ct - p.at;
    p.wt = p.tat - p.bt;
    p.display();
  }
}

int main() {
  std::vector<Process> procs = {
    {0, 2, 4}, {1, 1, 2}, {2, 0, 3}, {3, 4, 2}, {4, 3, 1}
  };

  FCFS(procs);

  return 0;
}
