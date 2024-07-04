/* shm_library.c */

#include "shm_library.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_NAME "/tmp/shm_fifo"

struct ShmHandle {
    int fd;
};

shm_handle shm_register(int pid) {
    // Open FIFO for writing
    int fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Error opening FIFO");
        return NULL;
    }

    // Write registration message
    char msg[50];
    snprintf(msg, sizeof(msg), "REGISTER %d", pid);
    if (write(fd, msg, strlen(msg)) == -1) {
        perror("Error writing to FIFO");
        close(fd);
        return NULL;
    }

    // Close FIFO
    close(fd);

    // Allocate memory for handle and store FIFO file descriptor
    struct ShmHandle *handle = malloc(sizeof(struct ShmHandle));
    handle->fd = fd;

    return (shm_handle)handle;
}

int shm_send_heartbeat(shm_handle handle) {
    struct ShmHandle *shm_handle = (struct ShmHandle *)handle;
    // Open FIFO for writing
    int fd = shm_handle->fd;
    if (fd == -1) {
        perror("Invalid handle");
        return SHM_FAILURE;
    }

    // Write heartbeat message
    char msg[50];
    snprintf(msg, sizeof(msg), "HEARTBEAT %d", getpid());
    if (write(fd, msg, strlen(msg)) == -1) {
        perror("Error writing to FIFO");
        return SHM_FAILURE;
    }

    return SHM_SUCCESS;
}

int shm_cancel(shm_handle handle) {
    struct ShmHandle *shm_handle = (struct ShmHandle *)handle;
    // Open FIFO for writing
    int fd = shm_handle->fd;
    if (fd == -1) {
        perror("Invalid handle");
        return SHM_FAILURE;
    }

    // Write cancellation message
    char msg[50];
    snprintf(msg, sizeof(msg), "CANCEL %d", getpid());
    if (write(fd, msg, strlen(msg)) == -1) {
        perror("Error writing to FIFO");
        return SHM_FAILURE;
    }

    // Close FIFO
    close(fd);

    // Free handle memory
    free(shm_handle);
    
    return SHM_SUCCESS;
}

int shm_heartbeat_kick(shm_handle handle) {
    struct ShmHandle *shm_handle = (struct ShmHandle *)handle;
    // Open FIFO for writing
    int fd = shm_handle->fd;
    if (fd == -1) {
        perror("Invalid handle");
        return SHM_FAILURE;
    }

    // Write heartbeat kick message
    char msg[50];
    snprintf(msg, sizeof(msg), "HEARTBEAT_KICK %d", getpid());
    if (write(fd, msg, strlen(msg)) == -1) {
        perror("Error writing to FIFO");
        return SHM_FAILURE;
    }

    return SHM_SUCCESS;
}
