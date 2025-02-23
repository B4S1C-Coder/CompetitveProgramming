#include <unistd.h>
#include <stdio.h>

int main() {
  static int x = 0;
  if (fork() && fork()) { // evaluates to (+ve && +ve) in initial parent, (0 && 0) in all child process
    // This will only execute in the initial parent process
    printf("Double fork block\n");
    fork(); // this call only gets executed in the inital parent process
  }
  // So in total 3 child processes + 1 parent process ===> hello printed 4 times.
  printf("Hello\n");
  x++;
  printf("%d\n", x);
  return 0;
}
