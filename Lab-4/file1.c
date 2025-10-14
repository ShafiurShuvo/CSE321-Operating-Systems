// Opening a file in read only mode (creating it if it doesn't exist).
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("output1.txt",O_RDONLY | O_CREAT,  0644);
	if (fd == -1){
	perror("output1.txt");
	return 1;
	}
	else{
	printf("File opened\n");
	}
		
}
