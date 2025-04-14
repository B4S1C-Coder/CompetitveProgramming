#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/wait.h>

#define SHM_NAME "/shm_example"
#define SEM_EMPTY "/sem_empty"
#define SEM_FULL "/sem_full"

int main() {
    // Setup shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(int));
    int* buffer = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // Setup semaphores
    sem_t* sem_empty = sem_open(SEM_EMPTY, O_CREAT, 0666, 1); // initially buffer is empty
    sem_t* sem_full  = sem_open(SEM_FULL,  O_CREAT, 0666, 0); // nothing to consume

    pid_t pid = fork();

    if (pid == 0) {
        // Consumer process
        for (int i = 0; i < 5; i++) {
            sem_wait(sem_full);
            printf("Consumer consumed: %d\n", *buffer);
            sem_post(sem_empty);
            sleep(1);
        }
        exit(0);
    } else {
        // Producer process
        for (int i = 0; i < 5; i++) {
            sem_wait(sem_empty);
            *buffer = i;
            printf("Producer produced: %d\n", i);
            sem_post(sem_full);
            sleep(1);
        }

        // Wait for consumer to finish
        wait(NULL);

        // Cleanup
        munmap(buffer, sizeof(int));
        close(shm_fd);
        shm_unlink(SHM_NAME);
        sem_close(sem_empty);
        sem_close(sem_full);
        sem_unlink(SEM_EMPTY);
        sem_unlink(SEM_FULL);
    }

    return 0;
}

