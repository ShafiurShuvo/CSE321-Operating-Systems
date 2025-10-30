#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *fib_seq = NULL;
int terms = 0;

struct search_params {
    int *indices;
    int count;
};

void* fibonacci(void* arg) {
    fib_seq = (int*)malloc((terms + 1) * sizeof(int));
    if (!fib_seq) {
        perror("Memory allocation failed");
        pthread_exit(NULL);
    }
    
    for (int i = 0; i <= terms; i++) {
        if (i == 0) fib_seq[i] = 0;
        else if (i == 1) fib_seq[i] = 1;
        else fib_seq[i] = fib_seq[i-1] + fib_seq[i-2];
    }

    pthread_exit(NULL);
}

void* search(void* param) {
    struct search_params *sp = (struct search_params*) param;
    for (int i = 0; i < sp->count; i++) {
        int idx = sp->indices[i];
        if (idx >= 0 && idx <= terms) {
            printf("result of search #%d = %d\n", i+1, fib_seq[idx]);
        } else {
            printf("result of search #%d = -1\n", i+1);
        }
    }
    pthread_exit(NULL);
}

int main() {
    printf("Enter the term of fibonacci sequence:\n");
    scanf("%d", &terms);

    pthread_t tid_gen, tid_search;

    pthread_create(&tid_gen, NULL, fibonacci, NULL);
    pthread_join(tid_gen, NULL);

    for (int i = 0; i <= terms; i++) {
        printf("a[%d] = %d\n", i, fib_seq[i]);
    }

    int s;
    printf("How many numbers you are willing to search?:\n");
    scanf("%d", &s);

    int *search_indices = (int*)malloc(s * sizeof(int));
    if (!search_indices) {
        perror("Memory allocation failed");
        free(fib_seq);
        return 1;
    }

    for (int i = 0; i < s; i++) {
        printf("Enter search %d:\n", i+1);
        scanf("%d", &search_indices[i]);
    }

    struct search_params sp;
    sp.indices = search_indices;
    sp.count = s;

    pthread_create(&tid_search, NULL, search, (void*)&sp);
    pthread_join(tid_search, NULL);

    free(fib_seq);
    free(search_indices);

    return 0;
}