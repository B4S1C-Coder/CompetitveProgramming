#include <unistd.h>
#include <stdio.h>

int main() {
  if (fork() || fork()) {
    printf("Double OR block\n");
    fork();
  }
  printf("Hello\n");
  return 0;
}
