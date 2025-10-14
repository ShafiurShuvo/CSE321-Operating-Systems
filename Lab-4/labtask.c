#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
	int even [4] ;
	int odd [4] ;
	int s [] = {1,2,3,4,5,6,7,8};
	int len = sizeof(s)/sizeof(s[0]);
	for (int i = 0; i<len; i++){
		if (s[i]%2 ==0) {
			even = s[i];
			printf("%d\n", s[i]);
			}
		else {
			odd = s[i];
			printf("%d\n", s[i]);
		}
	}
	
	pid_t pid1, pid2;
	pid1 = fork();
	if (pid1 > 0){
	printf("even\n");
	}
	else if (pid1 == 0) {
	wait(NULL);
	printf("odd\n");
	pid2 = fork();
		
		if (pid2 == 0){
		printf("length is %d\n", len);
		}
	}
}
