#include <stdio.h>
#include <signal.h>
 
int main()
{
    signal(SIGINT,SIG_IGN);
    signal(SIGQUIT,SIG_IGN);
    while(1)
    printf("This is in infinite loop\n");
    return 0;
}
