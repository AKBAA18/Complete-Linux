#include <pthread.h>
#include <stdio.h>
 
void* compute_prime (void* arg)
{
    int candidate = 2;
    int n = *((int*) arg);
 
    printf(" \n Started Thread functioning. \n");
 
    while (1)
     {
        int factor;
        int is_prime = 1;
 
        /* Test primality by successive division. */
        for (factor = 2; factor < candidate; ++factor)
        if (candidate % factor == 0)
        {      
            is_prime = 0;
            break;
        }
 
        /* Is this the prime number we are looking for? */
        if (is_prime)
        {
            if (--n == 0)
            {
                /* Return the desired prime number as the thread return value. */
 
                printf(" \n Exiting from Thread functioning. \n");
                return (void*) candidate;
            }
        }
        ++candidate;
    }
    return NULL;
}
 
int main ()
{
    pthread_t thread;
    int which_prime = 10000;
    int prime;
 
 
    pthread_create (&thread, NULL, &compute_prime, &which_prime);
 
    /* Do some other work here... */
 
    pthread_join (thread, (void*) &prime);
 
    printf("The %dth prime number is %d.\n", which_prime, prime);
 
    return 0;
}
