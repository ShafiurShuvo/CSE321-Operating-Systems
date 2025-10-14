// Opening a file in write only mode (creating it if it doesn't exist).
// Writing with write().
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("output2.txt",O_WRONLY | O_CREAT,  0644);
	if (fd == -1){
	perror("output2.txt");
	return 1;
	}
	else{
	write(fd, "Hello world!\n", 13);
	write(fd,"Good morning\n", 13);
	}
		
}
