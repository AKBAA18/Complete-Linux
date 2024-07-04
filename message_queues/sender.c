// gcc -o msg_posix_sender posix_msg_sender.c -lrt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>

#define QUEUE_NAME  "/test_queue"
#define MAX_SIZE    1024
#define MSG_STOP    "exit"

int main(int argc, char **argv)
{
    mqd_t mq;
    char buffer[MAX_SIZE];

    // Open a message queue   (mq, buffer, size, attribute)
    mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, NULL);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    printf("Send to queue: ");
    fflush(stdout);
    fgets(buffer, MAX_SIZE, stdin);

    // Send the message   
    //        int mq_send(mqd_t mqdes, const char msg_ptr[.msg_len], 
     //                   size_t msg_len, unsigned int msg_prio);
    if (mq_send(mq, buffer, strlen(buffer) + 1, 0) == -1) {
        perror("mq_send");
        exit(2);
    }

    // Close the queue
    mq_close(mq);

    return 0;
}


