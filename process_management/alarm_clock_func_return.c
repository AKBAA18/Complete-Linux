#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<signal.h>

void func()
{
	fputs("Completed ", stderr);
}


int main()
{
    system("date");
    alarm(10);
    signal(SIGALRM,func);
    sleep(10);
    fputs("\nChecking\n" , stderr);
    sleep(20);
    //while (1)
   // printf("HI\n");
    system("date");

    return 0;
}
