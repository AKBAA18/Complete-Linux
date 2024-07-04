// gcc -o msg_posix_receiver posix_mqg_receiver.c -lrt

#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>

#define QUEUE_NAME  "/test_queue"

int main()
{
    mqd_t mq;
    struct mq_attr attr;
    char *buffer;

    // Open the message queue
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    // Query the attributes of the message queue
    if (mq_getattr(mq, &attr) == -1) {
        perror("mq_getattr");
        exit(2);
    }

    // Allocate buffer for the maximum message size
    buffer = malloc(attr.mq_msgsize);
    if (buffer == NULL) {
        perror("malloc");
        exit(3);
    }

    // Receive the message
    if (mq_receive(mq, buffer, attr.mq_msgsize, NULL) == -1) {
        perror("mq_receive");
        free(buffer);
        exit(4);
    }

    printf("Received: %s\n", buffer);

    // Cleanup
    free(buffer);
    mq_close(mq);

    return 0;
}

