#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;
  int status;

  printf("Parent process: PID = %d\n", getpid());

  // Create child process
  pid = fork();

  if (pid < 0) {
    printf("Fork failed.\n");
    exit(1);
  }

  else if (pid == 0) {
    // Child Process
    printf("Child process PID = %d started ...\n", getpid());
    sleep(3);
    printf("Terminating child ...");
    exit(69);
  }

  else {
    printf("Parent process waiting for child(%d) to finish\n", pid);
    wait(&status);

    if (WIFEXITED(status)) {
      printf("Child exited normally. Status: %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
      printf("Child terminated with signal: %d\n", WTERMSIG(status));
    }
    printf("Parent process exiting.\n");
  }

  return 0;
}
