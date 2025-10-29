#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("Run the compiled file with the input in command line\n");
        return -1;
    }
    
    pid_t pid = fork();

    if (pid < 0){
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0){
        execv("sort", argv);
    }
    else{
        execv("oddeven", argv);
    }

    return 0;
}
