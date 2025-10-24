// Sender Process
// This program creates a shared memory segment,
// writes data to it, and then detaches from the segment.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(){
	pid_t p_id;
	p_id=getpid();
	void *s_m;
	char buff[200];
	int sm_id;
	sm_id=shmget((key_t)101,1024,0666|IPC_CREAT);  //actual address of shared memory
	printf("ID of sender process: %d\n",p_id);
	printf("Key of SM: %d\n",sm_id);
	s_m=shmat(sm_id,NULL,0); //address where shared memory is attached with our process
	printf("Process attached at %p with id %d\n",s_m,p_id);
	printf("Write data for sending:\n");
	read(0,buff,sizeof(buff));
	strcpy(s_m,buff);
	printf("Writting complete by process with id %d\n",p_id);
	printf("Data written: %s\n",(char *)s_m);

	return 0;
}

