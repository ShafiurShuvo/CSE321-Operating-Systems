// execute like -> ./t 5 8 7 9 6
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
        execv("sort", argv);  // binary file name of sort.c
    }
    else{
        execv("oddeven", argv);  // binary file name of oddeven.c
    }

    return 0;
}


