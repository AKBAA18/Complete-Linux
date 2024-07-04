#include <pthread.h>
#include<stdlib.h>
#include <stdio.h>
 
 
void* print_xs (void* unused)
{
	system("sleep 5");
   	fputc('k', stderr);
    	return NULL;
}
void* print_xs1 (void* unused)
{
    while (1)
        {
                system("sleep 5");
                fputc('a', stderr);

        }
    return NULL;
}
void* print_xs2 (void* unused)
{
    while (1)
        {
                system("sleep 5");
                fputc('s', stderr);

        }
    return NULL;
}

void* print_xs3 (void* unused)
{
    while (1)
        {
                system("sleep 5");
                fputc('h', stderr);

        }
    return NULL;
}
void* print_xs4 (void* unused)
{
    while (1)
        {
                system("sleep 5");
                fputc('a', stderr);

        }
    return NULL;
}
void* print_xs5 (void* unused)
{
    while (1)
        {
                system("sleep 5");
                fputc('y', stderr);

        }
    return NULL;
}


/* The main program. */
int main ()
{
    pthread_t thread_id;
 
    pthread_create(&thread_id, NULL, &print_xs, NULL);
    pthread_create(&thread_id, NULL, &print_xs1, NULL);
    pthread_create(&thread_id, NULL, &print_xs2, NULL);
    pthread_create(&thread_id, NULL, &print_xs3, NULL);
    pthread_create(&thread_id, NULL, &print_xs4, NULL);
    pthread_create(&thread_id, NULL, &print_xs5, NULL);
 
  
    system("sleep 5");
    fputs(" HI ", stderr);
    fputs("\n", stderr);
		

	    
	    return 0;
}
