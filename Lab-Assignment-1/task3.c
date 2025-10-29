#include <stdio.h>
#include <unistd.h> // for fork()
#include <sys/types.h> // for pid_t
#include <sys/wait.h>

int main() {
    pid_t a, b, c, count;

    a = fork();
    b = fork();
    c = fork();
    
    count = 3;
    if (a==0){
        printf("%d\n", getpid());
        if (getpid() % 2 != 0) {
            fork();
            count++;
        }
        
    }
    
    else if (b==0){
        printf("%d\n", getpid());
        if (getpid() % 2 != 0) {
            fork();
            count++;
        }
        
    }
    
    else if (c==0){
        printf("%d\n", getpid());
        if (getpid() % 2 != 0) {
            fork();
            count++;
        }
        
    }
    printf("Total process created:%d\n", count);

    return 0;
}
