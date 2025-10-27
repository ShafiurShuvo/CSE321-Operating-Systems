// A C program that creates multiple threads to perform different tasks
// such as printing even/odd numbers, finding factors of a number, and
// incrementing a shared variable with synchronization using semaphores.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int var = 50;
sem_t s;

void *even_odd(void *age) {
    int a = *(int *)age;
    printf("Checking even/odd for numbers up to %d\n", a);
    printf("Even numbers: ");
    for (int i = 1; i <= a; i++) {
        if (i % 2 == 0)
            printf("%d ", i);
    }
    printf("\nOdd numbers: ");
    for (int i = 1; i <= a; i++) {
        if (i % 2 != 0)
            printf("%d ", i);
    }
    printf("\n");
    return NULL;
}

void *factors(void *id) {
    int num = *(int *)id % 1000; // Take last 3 digits of the id
    printf("Factors of %d are: ", num);
    for (int i = 1; i <= num; i++) {
        if (num % i == 0)
            printf("%d ", i);
    }
    printf("\n");
    return NULL;
}

void *loop(void *arg) {
    for (int i = 0; i < 100; i++) {
        sem_wait(&s);
        var++;
        sem_post(&s);
    }
    return NULL;
}

int main() {
    int age = 25;
    int id = 21201613;
    pthread_t t1, t2, t3, t4;

    sem_init(&s, 0, 1);

    pthread_create(&t1, NULL, even_odd, &age);
    pthread_create(&t2, NULL, factors, &id);
    pthread_create(&t3, NULL, loop, NULL);
    pthread_create(&t4, NULL, loop, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
  
    sem_destroy(&s);

    printf("Final value of shared variable: %d\n", var);
    return 0;
}
