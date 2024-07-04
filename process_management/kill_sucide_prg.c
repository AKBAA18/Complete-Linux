#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
	printf("the pid is %d\n",getpid());
	kill(getpid(),SIGKILL);
	while(1)
	printf("this is infinite loop");
	return 0;
}
