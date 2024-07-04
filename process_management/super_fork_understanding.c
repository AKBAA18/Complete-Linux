#include<stdio.h>
#include<stdlib.h>//system
#include<sys/types.h>//pid_t
#include<unistd.h> //fork , getpid , getppid
		   //
int main()
{
	int new_pid;
	new_pid=fork();

	if(!new_pid)
	{
		printf("This id the child %d and its parent is %d" , getpid() , getppid());
	}
	if(new_pid!=0)
	{
		printf("This id the parent is  %d " , getpid() );
	}
	while(1)
	{
		sleep(5);
		printf("WAIT \n");
	}
	return 0;
}
	
