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
  for (int i = 0; i < numRes; i++) {
    if (p->need[i] > resAvailableMatrix[i]) {
      return false;
    }
  }
  return true;
}

void destroy_proc(struct Process* p) {
  free(p->allocated);
  free(p->max);
  free(p->need);
  free(p);
}

int* construct_res_available_matrix(int* numResBuf) {
  printf("Enter the number of resources> ");
  scanf("%d", numResBuf);

  int* resourceArray = (int*)malloc(sizeof(int) * (*numResBuf));
  for (int i = 0; i < *numResBuf; i++) {
    printf("Enter available res-%d> ", i);
    scanf("%d", &resourceArray[i]);
  }
  return resourceArray;
}

struct Process* construct_problem_matrix(int numRes, int* numProcReturnBuf) {
  printf("Enter the number of processes> ");
  scanf("%d", numProcReturnBuf);

  struct Process* allocationMatrix = (struct Process*)malloc(sizeof(struct Process) * (*numProcReturnBuf));
  for (int i = 0; i < *numProcReturnBuf; i++) {
    allocationMatrix[i] = *init_proc(i, numRes);
  }
  return allocationMatrix;
}

bool proceed_banker_algorithm(int* resAvailableMatrix, int numRes, struct Process* problemMatrix, int numProc) {
  for (int i = 0; i < numProc; i++) {
    if (!problemMatrix[i].isOutOfProblemMatrix && is_need_satisfied(&problemMatrix[i], resAvailableMatrix, numRes)) {
      for (int j = 0; j < numRes; j++) {
        resAvailableMatrix[j] += problemMatrix[i].allocated[j];
      }
      problemMatrix[i].isOutOfProblemMatrix = true;
      printf("P%d ", i);
      return true;
    }
  }
  return false;
}

bool is_system_safe(struct Process* problemMatrix, int numProc) {
  for (int i = 0; i < numProc; i++) {
    if (!problemMatrix[i].isOutOfProblemMatrix) {
      return false;
    }
  }
  return true;
}

int main() {
  int numRes, numProc;
  int* resAvailableMatrix = construct_res_available_matrix(&numRes);
  struct Process* problemMatrix = construct_problem_matrix(numRes, &numProc);

  printf("Safe Sequence: ");
  while (proceed_banker_algorithm(resAvailableMatrix, numRes, problemMatrix, numProc));

  if (is_system_safe(problemMatrix, numProc)) {
    printf("\nSystem is in a Safe State.\n");
  } else {
    printf("\nNo Safe Sequence Exists!\n");
  }

  free(resAvailableMatrix);
  for (int i = 0; i < numProc; i++) {
    destroy_proc(&problemMatrix[i]);
  }
  free(problemMatrix);
  return 0;
}

