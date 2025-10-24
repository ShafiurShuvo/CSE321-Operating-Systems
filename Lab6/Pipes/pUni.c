// Unidirectional communication using a single pipe between parent and child process
// Parent writes data to the pipe and child reads data from the pipe
// The parent process waits for the child process to complete before reading from the pipe
// This ensures that the child has finished writing data before the parent attempts to read it
// This prevents potential deadlocks and ensures proper synchronization between the processes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int fd[2];
	pid_t a;
	char buff[200];
	
	int p=pipe(fd);
	//printf("p: %d\n",p);
	if(p==-1){
		perror("pipe");
	}
	a=fork();
	if(a<0){
		perror("fork");
	}
	else if(a==0){ //child
		close(fd[0]); //cannot read, can only write in case of first pipe
		printf("Give input:\n");
		read(0,buff,sizeof(buff));
		printf("This is child and I am Writing data for sending_____\n");
		write(fd[1],buff,sizeof(buff));
		printf("Writing done from child end_____\n");
		close(fd[1]);
	}
	else{
		wait(NULL);
		close(fd[1]);
		printf("This is parent and I am Reading data after receiving_____\n");
		read(fd[0],buff,sizeof(buff));
		printf("Data received at parent end:\n%s\n",buff);
		close(fd[0]);
	}

	
	

	return 0;
}
