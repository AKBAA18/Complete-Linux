/* test_app.c */

#include "shm_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Register with the SHM library
    shm_handle handle = shm_register(getpid());
    if (handle == NULL) {
        fprintf(stderr, "Failed to register with SHM library\n");
        exit(1);
    }

    // Send heartbeats
    for (int i = 0; i < 5; i++) {
        if (shm_send_heartbeat(handle) == SHM_FAILURE) {
            fprintf(stderr, "Failed to send heartbeat\n");
            exit(1);
        }
        printf("Heartbeat sent\n");
        sleep(3); // Heartbeat interval: 3 seconds
    }

    // Send heartbeat kick
    if (shm_heartbeat_kick(handle) == SHM_FAILURE) {
        fprintf(stderr, "Failed to send heartbeat kick\n");
        exit(1);
    }
    printf("Heartbeat kick sent\n");

    // Cancel monitoring
    if (shm_cancel(handle) == SHM_FAILURE) {
        fprintf(stderr, "Failed to cancel monitoring\n");
        exit(1);
    }
    printf("Monitoring canceled\n");

    return 0;
}

