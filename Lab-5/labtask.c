#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int var = 50;
void *even_odd(void *age){
   if 
   return age;
}

void *factors(void *id){

  return id;
}

void *loop(void *loop){
  for(int i=0,i<100,i++){
      sem_wait(&s);
      var++;
      sem_post(&s);
  }
  return 0;
}

int main(){
	int age = 25
	int id = 21201613 
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	pthread_t t4;
	sem_init(&s,0,1);
	pthread_create(&t1,NULL,(void *)even_odd,(void *)age);
	pthread_create(&t2,NULL,(void *)factors,(void *)id);
	pthread_create(&t3,NULL,(void *)loop,(void *)var);
	pthread_create(&t4,NULL,(void *)loop,(void *)var);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	sem_destroy(&s);
	return 0;
}



