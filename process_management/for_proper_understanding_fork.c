#include<stdio.h> 
#include<stdlib.h> 
#include<sys/types.h> 
#include<unistd.h> 

int main() 
{ 
        pid_t result; 
        result=fork(); 
        printf("The pid is %d \n", getpid()); 
	printf("\n");
} 
