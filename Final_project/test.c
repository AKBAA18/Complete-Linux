/* shm_test_app.c */

#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int pid = getpid(); // Get the PID of the current process

    // Register with the SHM library
    if (shm_register(pid) == SHM_FAILURE) {
        fprintf(stderr, "Failed to register with SHM library\n");
        exit(1);
    }

    // Main loop to send heartbeats
    int heartbeat_count = 0;
    while (heartbeat_count < 10) { // Send 10 heartbeats
        // Send heartbeat
        if (shm_send_heartbeat(pid) == SHM_FAILURE) {
            fprintf(stderr, "Failed to send heartbeat\n");
            exit(1);
        }

        printf("Heartbeat sent\n");

        // Sleep for different intervals to simulate varying heartbeats
        if (heartbeat_count < 5) {
            sleep(3); // Heartbeat interval: 3 seconds
        } else {
            sleep(7); // Heartbeat interval: 7 seconds
        }

        heartbeat_count++;
    }

    // Cancel monitoring
    if (shm_cancel(pid) == SHM_FAILURE) {
        fprintf(stderr, "Failed to cancel monitoring\n");
        exit(1);
    }

    return 0;
}

