/* shm_library.h */

#ifndef SHM_LIBRARY_H
#define SHM_LIBRARY_H

#define SHM_SUCCESS 0
#define SHM_FAILURE -1

// Opaque handle type for application registration
typedef void* shm_handle;

// Function to register an application with the SHM daemon
shm_handle shm_register(int pid);

// Function to send a heartbeat to the SHM daemon
int shm_send_heartbeat(shm_handle handle);

// Function to cancel monitoring for an application
int shm_cancel(shm_handle handle);

// Function to send a heartbeat kick from the application
int shm_heartbeat_kick(shm_handle handle);

#endif

