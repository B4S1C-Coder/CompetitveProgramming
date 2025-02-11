#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  
  pid_t pid;
  int status;

  printf("Parent process started. PID = %d\n", getpid());
  
  // Create child process
  pid = fork();
  if (pid < 0) {
    printf("Fork failed.\n");
    exit(1);
  } else if (pid == 0) {
    // Child Process
    printf("Child process started. PID = %d\n", getpid());
    printf("Executing ls -l command ...\n");

    char* args[] = { "ls", "-l", NULL };

    if (execv("/bin/ls", args) == -1) {
      perror("execv failed");
      exit(1);
    }

    printf("Not printed if execv succeeds.\n");
  } else {
    // Parent Process
    printf("Parent waiting for child(%d) to finish.\n", pid);
    wait(&status);

    if (WIFEXITED(status)) {
      printf("Child exited normally with status: %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
      printf("Child terminated with signal: %d\n", WTERMSIG(status));
    }

    printf("Process finished.\n");
  }
  return 0;

  return 0;
}
