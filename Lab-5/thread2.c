// gcc -o thread2 thread2.c -lpthread
// This program demonstrates creating a thread that modifies a value and returns it.
// The main thread waits for the created thread to finish and retrieves the modified value.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* func_thread(void *arg);

int main() {
    pthread_t t1;
    int n = 5;
    int *t_ret;

    pthread_create(&t1, NULL, func_thread, &n);

    pthread_join(t1, (void**)&t_ret);

    printf("Thread returned: %d\n", *t_ret);
    return 0;
}

void* func_thread(void *arg) {
    int *v = (int*)arg;
    *v = (*v) * 5;
    return v;
}