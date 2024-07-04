#include<stdio.h>
#include<stdlib.h>
 
int main(int arg,char *arr[])
{
        FILE *fs,*ft; //Here we are creating the file pointer 
        char ch;// Creating a charecter for copying and moving the file text 
 
 
 	/*Below we are checking the number of arguments ./a.out file1 file2 
 	If the arguments are less than 3 it prints arguments missing */
        if(arg!=3) 
        {
                printf("Argument Missing !");
                exit(0);
        }
 
        fs = fopen(arr[1],"r");// fs is a fil;e mpointer that opens the file1 in read only mode  
        ft = fopen(arr[2],"w");// ft is a file pointer opens the file2 in write mode if any content present it overwrites it  
 
 	/*ft == NULL this condition finds whether the file is openable 
 	or it is not openable if not openable it is == NULL */
        if(ft==NULL)
        {
                printf("Cannot copy file !");
                fclose(fs);// This closes the file  
                exit(0);// this make the exit from the entire program 
        }
 	
 	/*While 1 is an infinite loop 
 	ch = getc(fs) getc function is a pointer that get the charecter by charecter from the file1 and append to ch 
 	if(ch==EOF) EOF refer to the end of file when there is nothing after the content of file  
 	if the condiution satisifies it breaks the while loop 
 	else putc(ch,ft) it append the charecter by charecter to file2  */
        while(1)
        {
                ch = getc(fs);
                if(ch==EOF)
                {
                        break;
                }
                else
                putc(ch,ft);
        }
 
        printf("\n File copied succesfully!\n");
 	/*fclose is a function that cloases the files file1 and file2 
 	It is recommended to cloase the file after the completion of the file 
 	Tge compiler also closes the file even we didnt close */
        fclose(fs);
        fclose(ft);
        /*The system function helps in using the linux command in c */
        system("cat 1.txt");
        system("cat 2.txt");
        return 0;
}
