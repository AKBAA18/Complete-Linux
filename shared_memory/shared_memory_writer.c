/* 
Compile:
=========
gcc shm_writer.c -o shm_writer -lrt
gcc shm_reader.c -o shm_reader -lrt

Run:
=====
./shm_writer
./shm_reader
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHM_NAME "/my_shm"
#define SHM_SIZE 4096

int main() {
    int shm_fd;
    void *ptr;

    // Open the shared memory object
    shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        return 1;
    }

    // Memory map the shared memory object
    ptr = mmap(0, SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Read from the shared memory object
    printf("%s\n", (char *)ptr);

    // Clean up
    munmap(ptr, SHM_SIZE);
    close(shm_fd);

    return 0;
}

