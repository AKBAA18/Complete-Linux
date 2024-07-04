/*
shm_library.h 

#ifndef SHM_LIBRARY_H
#define SHM_LIBRARY_H

#define SHM_SUCCESS 0
#define SHM_FAILURE -1

// Function to register an application with the SHM daemon
int shm_register(int pid);

// Function to send a heartbeat to the SHM daemon
int shm_send_heartbeat(int pid);

// Function to cancel monitoring for an application
int shm_cancel(int pid);

#endif

*/


/* shm_library.c */

#include "library.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_NAME "/tmp/shm_fifo"

int shm_register(int pid) {
    // Open FIFO for writing
    int fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Error opening FIFO");
        return SHM_FAILURE;
    }

    // Write registration message
    char msg[50];
    snprintf(msg, sizeof(msg), "REGISTER %d", pid);
    if (write(fd, msg, strlen(msg)) == -1) {
        perror("Error writing to FIFO");
        close(fd);
        return SHM_FAILURE;
    }

    // Close FIFO
    close(fd);
    return SHM_SUCCESS;
}

int shm_send_heartbeat(int pid) {
    // Open FIFO for writing
    int fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Error opening FIFO");
        return SHM_FAILURE;
    }

    // Write heartbeat message
    char msg[50];
    snprintf(msg, sizeof(msg), "HEARTBEAT %d", pid);
    if (write(fd, msg, strlen(msg)) == -1) {
        perror("Error writing to FIFO");
        close(fd);
        return SHM_FAILURE;
    }

    // Close FIFO
    close(fd);
    return SHM_SUCCESS;
}

int shm_cancel(int pid) {
    // Open FIFO for writing
    int fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Error opening FIFO");
        return SHM_FAILURE;
    }

    // Write cancellation message
    char msg[50];
    snprintf(msg, sizeof(msg), "CANCEL %d", pid);
    if (write(fd, msg, strlen(msg)) == -1) {
        perror("Error writing to FIFO");
        close(fd);
        return SHM_FAILURE;
    }

    // Close FIFO
    close(fd);
    return SHM_SUCCESS;
}

