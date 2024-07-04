#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>


sem_t sem1;//created varible for semaphore 

void *thrdFun1(void *arg);

int main()
{
	pthread_t thrd1;
	int res;
	
	res = sem_init(&sem1, 0, 1);// like initialising semaphore 
//	sem_post(&sem1);
	pthread_create(&thrd1, NULL, thrdFun1, NULL);		

	while(1)
	{
		printf("Main thread waiting for semaphore\n");
		sem_wait(&sem1);// if there is a semaphore it decrement from 1 to 0 
		printf("Main thread received semaphone. sleeping -> ");
		sleep(5);
		sem_post(&sem1);//increase semaphore value to 1 from 0 
		printf("Main thread released semaphore\n\n");
		sleep(1);
	}

	return 0;
}

void *thrdFun1(void *arg)
{
	while(1)
	{
		printf("Created thread sleepting \n");

		sleep(5);

		printf("Created thread waking up\n");
	}
}
