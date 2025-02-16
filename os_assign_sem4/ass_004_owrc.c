#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
  int fileDescriptor;
  char buffer[250];
  ssize_t bytesRead, bytesWritten;

  // Writing data to file

  fileDescriptor = open("os_assign_sem4/ass_004_test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
  if (fileDescriptor == -1) {
    printf("Error opening file.\n");
    return 1;
  }

  const char* message = "TEST DATA, to be written into the file.\nHello, there!";
  bytesWritten = write(fileDescriptor, message, strlen(message));

  if (bytesWritten == -1) {
    printf("Error writing to file.\n");
    close(fileDescriptor);
    return 1;
  }

  printf("Written %zd bytes ...\n", bytesWritten);

  if (close(fileDescriptor) == -1) {
    printf("Error closing file.\n");
    return 1;
  }

  // Reading data from file

  fileDescriptor = open("os_assign_sem4/ass_004_test.txt", O_RDONLY);
  if (fileDescriptor == -1) {
    printf("Error opening file.\n");
    return 1;
  }

  bytesRead = read(fileDescriptor, buffer, sizeof(buffer) - 1);
  if (bytesRead == -1) {
    printf("Error reading file.\n");
    return 1;
  }

  buffer[bytesRead] = '\0'; // NULL byte to terminate string
  printf("Read %zd bytes ...\n", bytesRead);

  if (close(fileDescriptor) == -1) {
    printf("Error closing file.\n");
    return 1;
  }

  return 0;
}
