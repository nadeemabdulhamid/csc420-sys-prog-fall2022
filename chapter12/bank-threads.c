#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *depositor(void *arg);
void *withdrawer(void *arg);
int balance = 0;

int main() {
    int res;
    pthread_t T1, T2;
    void *thread_result;

    res = pthread_create(&T1, NULL, depositor, NULL);    
    if (res != 0) {
        perror("Depositor creation failed");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&T2, NULL, withdrawer, NULL);    
    if (res != 0) {
        perror("Withdrawer creation failed");
        exit(EXIT_FAILURE);
    }


    printf("\nWaiting for threads to finish...\n");
    res = pthread_join(T1, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Done depositing. Balance: %d\n", balance);

    res = pthread_join(T2, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }

    printf("Final balance: %d\n", balance);

    exit(EXIT_SUCCESS);
}

void *depositor(void *arg) {
    int total = 0;
    for (int i = 0; i < 100; i++) {
        usleep(random() % 3);
        /* also, try this instead of the next three lines: 
        balance = balance + 10;
         */
        balance = balance + 4;
        usleep(random() % 3);
        balance = balance + 6; 
        printf("Dep: %d\n", balance);
        total += 10;
    }

    printf("Deposited total: %d\n", total);
    usleep(3);
    return NULL;
}

void *withdrawer(void *arg) {
    int total = 0;
    for (int i = 0; i < 100; i++) {
        while (balance <= 5) ;   /* can't do anything here */
        int x = balance;
        usleep(random() % 5);
        balance = x - 5;
        printf("With: %d\n", balance);
        total += 5;
    }

    printf("Withdrawn total: %d\n", total);
    usleep(3);
    return NULL;
}
