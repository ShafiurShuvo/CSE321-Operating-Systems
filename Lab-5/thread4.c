// gcc -o thread4 thread4.c -lpthread
// This program creates a thread that allocates an array, fills it with user input, and returns it to the main thread.
// The main thread then prints the values of the array.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int *func_thread(int *v);
int *t_ret;

int main(){
	pthread_t t1;
	int n;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
	pthread_create(&t1,NULL,func_thread,&n);
	pthread_join(t1,&t_ret);
	
    for(int i=0;i<n;i++){
        printf("a[%d]: %d\n",i,t_ret[i]);
    }
	free(t_ret);

	return 0;
}
int *func_thread(int *v){
    int *a=malloc(sizeof(int)*(*v));
    for(int i=0;i<*v;i++){
        printf("Enter value in a[%d]:\n",i);
        scanf("%d",&a[i]);
    }
    return a;
}
