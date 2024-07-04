#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *printtt( void* notuse)
{
	fputs("This is from the function printed by fputs " , stderr);
		fputs("\n",stderr);
}

int main()
{
	pthread_t thread_id;
	pthread_create (&thread_id , NULL , &printtt , NULL);
	while(1)
	{
		system("sleep 5");
		fputs("Infinity",stderr);
		fputs("\n",stderr);
	}
	return 0;
}

