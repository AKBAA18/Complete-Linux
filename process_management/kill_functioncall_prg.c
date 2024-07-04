#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
 
void myhandler(int signum)
{
    printf("Sent SIGINT to parent\n");
    kill(getppid(),SIGINT);

}
 
int main()
{
    int i;
   
    signal(SIGINT,myhandler);
    i=fork();  
   
    if(i==0) {
        kill(getppid(),SIGINT);
        printf("child pid is %d\n",getpid());
        sleep(5);
	printf("parent pid is %d\n",getppid());
     } else
     {
        sleep(2);
    }
    return 0;
} 
