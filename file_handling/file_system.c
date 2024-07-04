#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
 
int main()
{
    char c;
    int in, out;// file descriptor 
 
    in = open("1.txt", O_RDONLY);//O_RONLY refers to the read only format 
    out = open("2.txt", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR); 
    /*O_WRONLY specify the write mode where the previous content erased 
     O_CREAT if the file is present leave or else create it 
    S_IRUSR | S_IWUSR  helps the user to have read and write permission */
    while(read(in,&c,1) == 1)
        write(out,&c,1);
    /*read (in,&c,1) this helps in reading the charecter by charecter and write to c till end (==1 ) 
    write (out , &c , 1 ) This lhelps in writing charecter by charecter to the out from C 4e33*/
 
    printf("Source file => "); // When we are printing the by printf it sends to std buffer .The system function have more preference than printf   
    // fflush(stdout); // When we use the fflush function it flushes the buffers 
//  fputs("Source file => ", stderr);  //stderr dont use the buffer mechanism so it will be printed directly  
    system("cat 1.txt");//System function helps in using the linux commands 
    printf("Destination file => "); // When we are printing the by printf it sends to std buffer .The system function have more preference than printf  
    // fflush(stdout);// When we use the fflush function it flushes the buffers 
//  fputs("\nDestination file => ", stderr);//stderr dont use the buffer mechanism so it will be printed directly 
    system("cat 2.txt"); printf("\n\n");/System function helps in using the linux commands 
 
    return 0;
}
