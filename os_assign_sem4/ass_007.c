#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Process {
  int id;
  int* allocated;
  int* max;
  int* need;
  bool isOutOfProblemMatrix;
};

struct Process* init_proc(int id, int numRes) {
  struct Process* proc = (struct Process*)malloc(sizeof(struct Process));
  proc->allocated = (int*)malloc(sizeof(int) * numRes);
  proc->max = (int*)malloc(sizeof(int) * numRes);
  proc->need = (int*)malloc(sizeof(int) * numRes);
  proc->isOutOfProblemMatrix = false;

  for (int i = 0; i < numRes; i++) {
    printf("Enter allocated res-%d> ", i);
    scanf("%d", &proc->allocated[i]);

    printf("Enter max res-%d> ", i);
    scanf("%d", &proc->max[i]);

    proc->need[i] = proc->max[i] - proc->allocated[i];
  }

  return proc;
}

bool is_need_satisfied(struct Process* p, int* resAvailableMatrix, int numRes) {
  bool verdict = false;
  int numResNeedMet = 0;

  for (int i = 0; i < numRes; i++) {
    if (p->need[i] <= resAvailableMatrix[i]) {
      numResNeedMet++;
    }
  }

  if (numResNeedMet == numRes) {
    verdict = true;
  }

  return verdict;
}

void destroy_proc(struct Process* p) {
  free(p->allocated);
  free(p->max);
  free(p->need);
  free(p);
}

int* construct_res_available_matrix(int* numResBuf) {
  printf("Enter the number of resources> ");

  int numRes;
  scanf("%d", &numRes);

  int* resourceArray = (int*)malloc(sizeof(int)*numRes);

  for (int i = 0; i < numRes; i++) {
    printf("Enter available res-%d> ", i);
    scanf("%d", &resourceArray[i]);
  }

  *numResBuf = numRes;
  return resourceArray;
}

struct Process* construct_problem_matrix(int numRes, int* numProcReturnBuf) {
  printf("Enter the number of processes> ");

  int numProc;
  scanf("%d", &numProc);

  struct Process* allocationMatrix = (struct Process*)malloc(sizeof(struct Process)*numProc);
  for (int i = 0; i < numProc; i++) {
    allocationMatrix[i] = init_proc(i, numRes);
  }

  *numProcReturnBuf = numProc;
  return allocationMatrix;
}

// This function is essentially one iteration of Banker's Algorithm
bool proceed_banker_algorithm(
  int* resAvailableMatrix, int numRes, struct Process* problemMatrix, int numProc
) {
  // Identify the first process whose need can be satisfied.
  int i;
  bool processFound = false;

  for (i = 0; i < numProc; i++) {
    if(is_need_satisfied(problemMatrix[i], resAvailableMatrix, numRes)) {
      processFound = true;
      break;
    }
  }

  if (!processFound) {
    return false; // No longer meaningful to proceed with the next iteration of the algorithm
  }

  // If the process is found, we will then satisfy this process and remove it from the problem matrix
  // Update the resource available matrix
  for (int j = 0; j < numProc; j++) {
    resAvailableMatrix[j] += problemMatrix[i]->max[j];

    // Set these to extreme, so they are effectively ignored in the next iterations of the algorithm
    problemMatrix[i]->allocated[j] = INT_MIN;
    problemMatrix[i]->need[j] = INT_MAX;
    problemMatrix[i]->isOutOfProblemMatrix = true;
  }

  printf("P%d ", i);

  return true; // Ok to proceed with next iteration of the algorithm
}

bool is_system_safe(struct Process* problemMatrix, int numProc) {
  bool verdict = false;
  int processesSatisfied = 0;

  for (int i = 0; i < numProc; i++) {
    if (problemMatrix[i]->isOutOfProblemMatrix) {
      processesSatisfied++;
    }
  }

  if (processesSatisfied == numProc) {
    verdict = true;
  }

  return verdict;
}

int main() {
  int numRes, numProc;
  int* resAvailableMatrix = construct_res_available_matrix(&numRes);
  struct Process* problemMatrix = construct_problem_matrix(numRes, &numProc);

  // Execute Algorithm

  return 0;
}
