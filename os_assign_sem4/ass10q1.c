#include <pthread.h>
#include <stdio.h>

int data[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int sum = 0, max = 0, min = 0;

void *calc_sum(void *arg) {
    sum = 0;
    for (int i = 0; i < 10; i++) sum += data[i];
    pthread_exit(NULL);
}

void *find_max(void *arg) {
    max = data[0];
    for (int i = 1; i < 10; i++) if (data[i] > max) max = data[i];
    pthread_exit(NULL);
}

void *find_min(void *arg) {
    min = data[0];
    for (int i = 1; i < 10; i++) if (data[i] < min) min = data[i];
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];

    pthread_create(&threads[0], NULL, calc_sum, NULL);
    pthread_create(&threads[1], NULL, find_max, NULL);
    pthread_create(&threads[2], NULL, find_min, NULL);

    for (int i = 0; i < 3; i++) pthread_join(threads[i], NULL);

    printf("Sum: %d\n", sum);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}

