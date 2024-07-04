#include <stdio.h> // printf 
#include <stdlib.h> // system
#include <sys/types.h> // pid_t 
#include <unistd.h>// fork , vfork 
#include <time.h>
#include <sys/stat.h> 
 
 
int init_daemon(void);
 
int main()
{
    init_daemon();
   
    for(;;)
    {
            printf("Daemon running\n");
            sleep(5);
       
    }
    return 0;
}
 
// Code to creat a daemon
int init_daemon(void)      
{
    int pid;
 
    pid = fork();
 
    if(!pid)
    {
        printf("PID of daemon process is = %d /n", getpid());
        setsid();   // set new session, Disassociate the process from the tt
        chdir("/"); // Change the current working directory to root. make it the process group leader
        umask(0);   //change mode similar to chmod 0,   unmask the file mode,
        return(0);
    }
    return 0;
}
