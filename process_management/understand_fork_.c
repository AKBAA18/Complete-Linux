#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
 {
        pid_t result; // pid_ t is a datatype for the holding of pid 
        int i=0;
        while(i<6)
         {
                 system("sleep 5 ");
                 result=fork();//This will either give the child or parent pid 
                printf("The pid is %d \n", getpid());//getpid is a function call for printing the pid of process running :wq

                i++;
         }
 }
~      
