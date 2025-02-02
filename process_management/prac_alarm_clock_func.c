#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
 
 
static int alarm_fired = 0;
 
void ding(int sig)
{
    alarm_fired = 1;
}
 
 
int main()
{
    int pid;
 
    printf("alarm application starting\n");
 
    if((pid = fork()) == 0) {
        sleep(5);
        kill(getppid(), SIGALRM);
        exit(0);
    }
 
 
    printf("waiting for alarm to go off\n");
    (void) signal(SIGALRM, ding);
 
    pause();
    if (alarm_fired)
        printf("Ding!\n");
 
    printf("done\n");
    exit(0);
}

