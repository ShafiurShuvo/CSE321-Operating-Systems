// The child process prints its own PID and its parent's PID.
// The parent process prints its own PID and the child's PID after the child process has completed.
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	pid = fork();
	if (pid == 0){
		printf("I'm the child process. My pid is %d and my parent's pid is %d\n", getpid(), getppid());
		}
	else if (pid > 0){
		wait(NULL);
		printf("I'm the parent process. My pid is %d and my child's pid is %d\n",getpid(), pid);
		}
	else{
		perror("error in fork");
		}
}
