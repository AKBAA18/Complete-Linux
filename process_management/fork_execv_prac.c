#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
 
int main()
 {
    pid_t pid;
    pid = vfork();
    if(pid == 0)
    {
        printf("in Child Process : This line will print\n");
        execv("./hello",0);
        printf("in Child Process : This will not be printed\n");
        exit(0);
    }
    else
    {
        printf(" Parent process message printed with pid %d\n",getpid());
       
    }  
    return 0;
}  
