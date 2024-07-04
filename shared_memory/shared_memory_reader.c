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
/*
Run:
=====
./shm_writer
./shm_reader
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHM_NAME "/my_shm"
#define SHM_SIZE 4096

int main() {
    int shm_fd;
    void *ptr;

    // Create the shared memory object
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        return 1;
    }

    // Configure the size of the shared memory object
    ftruncate(shm_fd, SHM_SIZE);

    // Memory map the shared memory object
    // void *mmap(void addr[.length], size_t length, int prot, int flags, int fd, off_t offset);
    // addr 0 means kernel will return page alinged available address. If addr is given then nearest page aligned address will be returned.
    ptr = mmap(0, SHM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Write to the shared memory
    sprintf(ptr, "Hello from shared memory!");

    return 0;
}

