// execl() to execute the commands.
s// The child process executes the "ls -a -l" command.
// The parent process executes the "pwd" command.
#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t pid1, pid2;
	pid1 = fork();
		if (pid1 == 0){
		execl("/bin/ls", "ls", "-a", "-l", NULL);
		
		}
	else if (pid1 > 0){
		execl("/bin/pwd", "pwd", NULL);
		}
	else {
	perror("fork faield");
	}
	return 0;
}
