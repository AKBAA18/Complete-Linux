#include<stdio.h>//printf
#include<stdlib.h>//exit 
#include<sys/types.h>//pid_t
#include<unistd.h>//getpid , fork , vfork 
		  //
int main()
{
	pid_t result ;
	result=fork(); //here the result is forked it will be executed 2 times 
	if(result==0)
	{
		printf("The child process %d" , getpid());
		printf("\n");
	}
	if(result>=1)
        {
                printf("The parent process %d" , getpid());
                printf("\n");
        }

	return 0;
}



