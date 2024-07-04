#include<stdio.h>
#include<stdlib.h> // system
#include<unistd.h> //open , read , write
#include<fcntl.h> // O_RDONLY , O_WRONLY  , O_CREAT
#include<sys/stat.h>	  // IRUSE , IWUSR

int main()
{
	char ch;
	int in , out ;// in and out is a file descriptornthat helps us to  open a file 

	in=open("1.txt" , O_RDONLY);
	out = open("2.txt" , O_WRONLY| O_CREAT , S_IRUSR | S_IWUSR); //IRUSR IWUSR GIVES THE READ AND WRITE USER 
	
	while(read(in,&ch,1) ==1 )
	{
		write(out,&ch,1);
	}

	fprintf(stderr,"File 1 ");
	system("cat 1.txt");
	fputs("\n" , stderr);
	fprintf(stderr,"File 2 ");
	system("cat 1.txt");

	return 0;
}

