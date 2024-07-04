#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
 
void sighandler(int signum)
{
    printf("Caught signal:%d pressed ctrl+c!!\n",signum);
    sleep(2);
}
 
int main()
{
    signal(SIGINT,sighandler);
    while(1)
    printf("This is an infinite loop\n");
}
