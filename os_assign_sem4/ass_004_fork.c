#include <stdio.h>
#include <unistd.h>

int main() {
  for (int i = 0; i < 3; i++) {
    pid_t childPid = fork();

    if (childPid == 0) {
      printf("Child Process - %d: PID = %d\n", i + 1, getpid());
      break; // Child process break out of loop, parent continues
    } else if (childPid < 0) {
      perror("Fork failed.");
    }
  }
  
  // Only executed by parent process
  if (getpid() != 1) {
    printf("Parent process: PID = %d\n", getpid());
  }

  return 0;
}
