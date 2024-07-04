#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
pid_t result; // Variable to hold process IDs
int i = 0;


// Loop to create child processes
while (i < 6) {
    system("sleep 5 "); // Pause the execution for 5 seconds

    result = fork(); // Create a new process

    // Check if fork() was successful
    if (result < 0) {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (result == 0) {
        // Child process
        printf("Child pid: %d\\n", getpid()); // Print child process ID
        exit(EXIT_SUCCESS); // Terminate child process
    } else {
        // Parent process
        printf("Parent pid: %d\\n", getpid()); // Print parent process ID
    }

    i++; // Increment the counter
}

return 0;


}
