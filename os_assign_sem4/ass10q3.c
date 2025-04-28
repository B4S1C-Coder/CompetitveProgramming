#include <pthread.h>
#include <stdio.h>

#define NUM_ACCOUNTS 3
#define NUM_THREADS 2

pthread_mutex_t lock;
int accounts[NUM_ACCOUNTS] = {1000, 2000, 3000}; // Initial balances

void *deposit(void *arg) {
    int account = *(int *)arg;
    pthread_mutex_lock(&lock);
    accounts[account] += 500;
    printf("Deposited 500 to Account %d. New balance: %d\n", account, accounts[account]);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

void *withdraw(void *arg) {
    int account = *(int *)arg;
    pthread_mutex_lock(&lock);
    if (accounts[account] >= 300) {
        accounts[account] -= 300;
        printf("Withdrew 300 from Account %d. New balance: %d\n", account, accounts[account]);
    } else {
        printf("Insufficient funds in Account %d for withdrawal.\n", account);
    }
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS * NUM_ACCOUNTS];
    int account_indices[NUM_ACCOUNTS] = {0, 1, 2};

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < NUM_ACCOUNTS; i++) {
        pthread_create(&threads[i * 2], NULL, deposit, &account_indices[i]); // Deposit thread
        pthread_create(&threads[i * 2 + 1], NULL, withdraw, &account_indices[i]); // Withdraw thread
    }

    for (int i = 0; i < NUM_THREADS * NUM_ACCOUNTS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    for (int i = 0; i < NUM_ACCOUNTS; i++) {
        printf("Final balance of Account %d: %d\n", i, accounts[i]);
    }

    return 0;
}

