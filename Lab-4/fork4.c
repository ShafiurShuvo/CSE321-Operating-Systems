// Creating a child process and a grandchild process using fork() system call.
// The parent process prints its own PID.
// The first child process prints its own PID and the grandchild's PID.
// The grandchild process prints its own PID.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    pid1 = fork();

    if (pid1 == 0) {
        printf("First child process (pid: %d)\n", getpid());
        pid2 = fork();
        if (pid2 == 0) {
            printf("Second child process (grandchild) (pid: %d)\n", getpid());
        } else if (pid2 > 0) {
            wait(NULL);
            printf("First child process (parent of grandchild) (pid: %d, grandchild pid: %d)\n", getpid(), pid2);
        } else {
            perror("Error in fork (grandchild)");
        }
    } 
    else if (pid1 > 0) {
        wait(NULL);
        printf("Parent process (pid: %d)\n", getpid());
    } 
    else {
        perror("Error in fork (child)");
    }

    return 0;
}
