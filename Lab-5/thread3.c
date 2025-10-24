// gcc -o thread3 thread3.c -lpthread
// This program creates a thread that allocates an array, fills it with user input, and returns it to the main thread.
// The main thread then prints the values of the array.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* func_thread(void *arg);

int main() {
    pthread_t t1;
    int n;
    int *t_ret;

    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    pthread_create(&t1, NULL, func_thread, &n);
    pthread_join(t1, (void**)&t_ret);

    for (int i = 0; i < n; i++) {
        printf("a[%d]: %d\n", i, t_ret[i]);
    }

    // Free allocated memory from thread
    free(t_ret);

    return 0;
}

// Thread function — allocates and fills an array
void* func_thread(void *arg) {
    int n = *(int*)arg;
    int *a = malloc(sizeof(int) * n);
    if (!a) {
        perror("Memory allocation failed");
        pthread_exit(NULL);
    }

    for (int i = 0; i < n; i++) {
        printf("Enter value in a[%d]:\n", i);
        scanf("%d", &a[i]);
    }

    return a;
}
