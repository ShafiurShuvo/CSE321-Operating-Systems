// Writing a string to the file
// reading the string back, and
// printing the string to the console.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("output4.txt",O_RDWR | O_CREAT,  0644);
	char s1 []  = "C Programming\n";
	char buffer [80];
		
	if (fd == -1){
	perror("output4.txt");
	return 1;
	}
	else{
	write(fd, s1, sizeof(s1)-1);
	lseek(fd,0,0);
	read(fd, buffer,sizeof(s1));
	printf("The buffer contains %s", buffer);
	}
	close(fd);
}