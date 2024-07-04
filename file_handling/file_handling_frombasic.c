#include<stdio.h>
#include<stdlib.h>//FILE

int main(int ar , char *arr[])
{
	FILE *f1 , *f2;
	char ch;

	if(ar!=3) 
	{
		printf("Enter the correct number arguments \n");
		exit(0);
	}

	f1=fopen(arr[1],"r"); // file pointer opening file for reading  
	f2=fopen(arr[2],"w"); // file pointer opening another file with write mode 
	
	if(f2==NULL)//if a file cant be opened it will be in NULL state 
	{
		printf("Cant copy the file \n");
		fclose(f2);
		exit(0);
	}
	while(1)
	{
		ch =getc(f1);
		if(ch == EOF)
		{
			break;

		}
		putc(ch,f2); // charecter from file1 is copied to file2 
	}
	printf("BYE file compiled successfully \n");
	fclose(f1);
	fclose(f2);
	printf("\n\n Now we are going to print by system command ");
	system("cat file1.txt");
	system("cat file2.txt");
	
	return 0;
}

