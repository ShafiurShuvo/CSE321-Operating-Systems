// Bidirectional communication using two pipes between parent and child process
// One pipe for parent to child communication and another for child to parent communication

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(){
	int fd[2],fd1[2];
	pid_t a;
	char buff[200];
	
	int pipe_1=pipe(fd);
	int pipe_2=pipe(fd1);
	if(pipe_1==-1){
		perror("pipe_1");
	}
	if(pipe_2==-1){
		perror("pipe_2");
	}
	a=fork();
	if(a<0){
		perror("fork");
	}
	else if(a==0){
		close(fd[0]);  //cannot read, can onlu write in case of first pipe
		close(fd1[1]); //cannot write, can only read in case of second pipe
		printf("Give input in pipe_1:\n");
		read(0,buff,sizeof(buff));
		printf("This is child and I am Writing data for sending in pipe_1_____\n");
		write(fd[1],buff,sizeof(buff));
		printf("Writing in pipe_1 done_____\n");
		printf("This is child and I am Reading data after receiving from pipe_2_____\n");
		read(fd1[0],buff,sizeof(buff));
		printf("Data received from pipe_2:\n%s\n",buff);
		close(fd[1]);
		close(fd1[0]);
	}
	else{ //parent
		close(fd1[0]);  //cannot write, can only read
		close(fd[1]);   //cannot read, can only write
		printf("Give input in pipe_2:\n");
		read(0,buff,sizeof(buff));
		printf("This is parent and I am Writing data for sending in pipe_2_____\n");
		write(fd1[1],buff,sizeof(buff));
		printf("Writing in pipe_1 done_____\n");
		printf("This is parent and I am Reading data after receiving from pipe_1_____\n");
		read(fd[0],buff,sizeof(buff));
		printf("Data received from pipe_1:\n%s\n",buff);
		close(fd1[1]);
		close(fd[0]);
	}

	return 0;
}
