// Writing a string to the file.
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("output3.txt",O_WRONLY | O_CREAT,  0644);
	char s1 []  = "C Programming\n";
		
	if (fd == -1){
	perror("output3.txt");
	return 1;
	}
	else{
	write(fd, s1, sizeof(s1)-1);
	}
	close(fd);
}
