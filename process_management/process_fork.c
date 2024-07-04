#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
 
int main()
 {
    pid_t result;//pid_t is the system od a special datatype to strore the process id 
    int i=10;
    result = fork();//here parent will be duplicated and the ./a.out file will be created twice 
		    //when fork called a duplicate process will be created 
    if(result == 0)
    {//if result ==0 child prrocess 
   
        printf(" Child process message printed with pid %d\n",getpid());
        i=20;
        printf("the value of i is %d\n",i);
        exit(0);
    }
    else
    {//if result === some other integer other than 0 it is the parent id  
           printf(" Parent process message printed with pid %d\n",getpid());
           printf("the value of i is %d\n",i);
       
    }  
}
