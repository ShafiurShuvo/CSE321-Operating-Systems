#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define max_students 10
#define chairs 3

sem_t waiting;
sem_t st_ready;
pthread_mutex_t mutex;

int waiting_students = 0;
int served_students = 0;
int done = 0;

void* students(void* arg) {
    int id = *(int*)arg;
    sleep(rand() % 3); // random arrival

    pthread_mutex_lock(&mutex);
    if (waiting_students < chairs) {
        printf("Student %d started waiting for consultation\n", id);
        waiting_students++;
        sem_post(&waiting); // notify tutor
        pthread_mutex_unlock(&mutex);

        sem_wait(&st_ready);
        printf("Student %d is getting consultation\n", id);

        sleep(1);

        pthread_mutex_lock(&mutex);
        printf("Student %d finished getting consultation and left\n", id);
        served_students++;
        printf("Number of served students: %d\n", served_students);

        // When last student served, signal done
        if (served_students == max_students) {
            done = 1;
            sem_post(&waiting); // unblock tutor if waiting
        }

        pthread_mutex_unlock(&mutex);
    } else {
        printf("No chairs remaining in lobby. Student %d leaving...\n", id);
        pthread_mutex_unlock(&mutex);
    }

    free(arg);
    pthread_exit(NULL);
}

void* st(void* arg) {
    while (1) {
        sem_wait(&waiting); // wait for a student

        pthread_mutex_lock(&mutex);
        if (done) { // check termination condition
            pthread_mutex_unlock(&mutex);
            break;
        }

        if (waiting_students > 0) {
            printf("A waiting student started getting consultation\n");
            waiting_students--;
            printf("Number of students now waiting: %d\n", waiting_students);
            printf("ST giving consultation\n");
            sem_post(&st_ready);
        }
        pthread_mutex_unlock(&mutex);
    }

    printf("All students have been served. Tutor is leaving.\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t tutor_thread;
    pthread_t student_threads[max_students];

    srand(time(NULL));
    sem_init(&waiting, 0, 0);
    sem_init(&st_ready, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&tutor_thread, NULL, st, NULL);

    for (int i = 0; i < max_students; i++) {
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&student_threads[i], NULL, students, id);
    }

    for (int i = 0; i < max_students; i++) {
        pthread_join(student_threads[i], NULL);
    }

    pthread_join(tutor_thread, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&waiting);
    sem_destroy(&st_ready);

    return 0;
}
