#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main()
{
    system("date");
    alarm(10);
    while (1)
    ;
    system("date");
    return 0;
}
