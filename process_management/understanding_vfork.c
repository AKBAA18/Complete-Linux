#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
 
int main()
 {
    pid_t result;
    int i=10;
    result = vfork();
    if(result == 0)
    {//this is the child process 
   
        printf(" Child process message printed with pid %d\n",getpid());
    	while(1){
		system("sleep 5");
		printf("The child pid is %d\n" , getpid());
	}
    }
    else
    {
           printf(" Parent process message printed with pid %d\n",getpid());
    		while(1){
			system("sleep 5");
			printf("The parent pid is %d\n" , getpid());
		}
      	 
    }  
}
