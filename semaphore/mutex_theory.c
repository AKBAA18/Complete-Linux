#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Shared resource
int shared_resource = 0;

// Mutex for synchronizing access to the shared resource
pthread_mutex_t mutex;
pthread_mutexattr_t attr;

// Thread function that modifies the shared resource
void* modify_resource(void* arg)
{
    for (int i = 0; i < 5; ++i) 
    {
        // Lock the mutex before accessing the shared resource
        pthread_mutex_lock(&mutex);

        // Modify the shared resource
        shared_resource++;
        printf("Thread %ld modified the shared resource to %d\n", (long) arg, shared_resource);

        // Unlock the mutex after accessing the shared resource
        pthread_mutex_unlock(&mutex);
			  sleep(5);
    }

    return NULL;
}

int main() 
{
    pthread_t thread1, thread2;

    // Initialize the mutex attribute
    pthread_mutexattr_init(&attr);

    // Set the mutex as an error-checking mutex
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);

    // Initialize the mutex with the attribute
    pthread_mutex_init(&mutex, &attr);

    // Create two threads
    pthread_create(&thread1, NULL, modify_resource, (void*)1);
    pthread_create(&thread2, NULL, modify_resource, (void*)2);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex and attribute
    pthread_mutex_destroy(&mutex);
    pthread_mutexattr_destroy(&attr);

    printf("Final value of shared resource: %d\n", shared_resource);

    return 0;
}
