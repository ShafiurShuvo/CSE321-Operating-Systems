// Compile with: gcc -o thread1 thread1.c -lpthread
// Run with: ./thread1
// This program creates a thread that runs concurrently with the main function.
// The thread prints numbers from 0 to 4, while the main function also prints numbers from 0 to 4.
// The output may vary in order due to the concurrent execution of the thread and main function.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *funcThread(void *arg);

void func1(){
	printf("Entered func1:\n");
	for(int i=0;i<5;i++){
		printf("func1: %d\n",i);
		sleep(1);
	}
	printf("Done with func 1....\n");

}

int main(){
	pthread_t t1;
	pthread_create(&t1,NULL,(void*)funcThread,NULL);
	func1();
	pthread_join(t1,NULL);
	
	return 0;
}

void *funcThread(void *arg){
	printf("Entered thread1:\n");
	for(int i=0;i<5;i++){
		printf("thread: %d\n",i);
		//sleep(1);
	}
	printf("Done with thread 1....\n");
}
