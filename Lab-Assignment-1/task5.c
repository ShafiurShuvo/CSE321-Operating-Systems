#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t a, b, c, d;

    a = fork();
    
    if (a==0){
        printf("Child process ID: %d\n", getpid());
        
        b = fork();
        if (b>0){
            wait(NULL);
            c = fork();
            if (c>0){
                wait(NULL);
                d = fork();
                if(d == 0){  // Third Grandchild
                     wait(NULL);
                     printf("Grandchild process ID:%d\n", getpid());
                }
            }
            else if(c==0){  // Second Grandchild
                printf("Grandchild process ID:%d\n", getpid());
            }
        }
        else if(b==0){  // First Grandchild
            printf("Grandchild process ID:%d\n", getpid());
        }
    }
    else if (a>0){
        printf("Parent process ID:%d\n", getpid());
        wait(NULL);
        }
    return 0;
}