#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
void func()
{
	fputs("Bye ",stderr);
	kill(getpid(),SIGKILL);
}

int main()
{
	printf("the pid is %d\n",getpid());
	kill(getpid(),SIGKILL);
	signal(SIGKILL , func);
	while(1)
	//printf("this is infinite loop");
	return 0;
}
