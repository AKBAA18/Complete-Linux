#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    char c;
    int in, out;

    in = open("1.txt", O_RDONLY);
    out = open("2.txt", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    while(read(in,&c,1) == 1)
        write(out,&c,1);

//    printf("Source file => ");
//    fflush(stdout);
  fputs("Source file => ", stderr);  
    system("cat 1.txt");
//    printf("Destination file => ");
//    fflush(stdout);
  fputs("\nDestination file => ", stderr);
    system("cat 2.txt"); printf("\n\n");

    return 0;
}

