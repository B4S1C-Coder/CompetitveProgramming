#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t sem;
int shared_var = 0;

void *thread1_func(void *arg) {
    sem_wait(&sem); 
    for (int i = 0; i < 5; i++) {
        shared_var++;
        printf("Thread 1: shared_var = %d\n", shared_var);
    }
    sem_post(&sem); 
    pthread_exit(NULL);
}

void *thread2_func(void *arg) {
    sem_wait(&sem); 
    for (int i = 0; i < 5; i++) {
        shared_var--;
        printf("Thread 2: shared_var = %d\n", shared_var);
    }
    sem_post(&sem); 
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    sem_init(&sem, 0, 1);

    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&sem);

    printf("Final value of shared_var: %d\n", shared_var);
    return 0;
}

