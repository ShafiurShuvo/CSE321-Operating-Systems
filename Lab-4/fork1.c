// Creating a child process using fork() system call.
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	pid = fork();
	if (pid == 0){
		printf("I'm the child process, my pid %d and my child's pid is %d\n", getpid(),pid);
		}
	else if (pid > 0){
		printf("I'm the parent process. My pid %d and my child's pid is %d\n",getpid(), pid);
		}
	else{
		perror("error in fork");
		}
}
