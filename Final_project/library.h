/* shm_library.h */

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

