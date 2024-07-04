#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
 
void ctrl_c(int signum)
{
    printf("Caught signal:%d pressed ctrl+c!!\n",signum);
    sleep(2);
}

void ctrl_z(int signum)
{
    printf("Caught signal:%d pressed ctrl+z!!\n",signum);
    sleep(2);
}
void ctrl_backslash(int signum)
{
    printf("Caught signal:%d pressed ctrl+backslash!!\n",signum);
    sleep(2);
}



int main()
{
    signal(SIGINT,ctrl_c);
    signal(SIGTSTP,ctrl_z);
    signal(SIGQUIT,ctrl_backslash);

    while(1)
    printf("This is an infinite loop\n");
}
