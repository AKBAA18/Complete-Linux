#include <stdio.h>
#include <stdlib.h>
#include<signal.h>
 
void handle(void);
 
int main()
{
    int j;
    signal(SIGFPE,handle);
    j = 8/0;
    return 0;
}
 
void handle(void)
{
    printf(" Test Program : Floating Point Error\n");
    exit(0);
}    
