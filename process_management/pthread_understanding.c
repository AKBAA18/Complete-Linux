#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
 
void *func(void* unused)
{
    fprintf(stderr, "child thread pid is %d\n",getpid());
 
  //  while(1)
    printf("hai\n");
}
 
 
int main()
{
    pthread_t th;
 
    fprintf(stderr, "parent thread pid is %d\n", getpid());
    pthread_create(&th, NULL, &func, NULL);
 
    //while(1)
    printf("hello\n");
    pthread_join(th,NULL);
    //system(sleep(10));
    
    printf("Bye \n");
    return 0;
}
