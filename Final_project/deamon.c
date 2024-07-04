/* shm_daemon.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define MAX_APPS 10
#define HEARTBEAT_INTERVAL 5 // in seconds
#define FIFO_NAME "/tmp/shm_fifo"
#define LOG_FILE "shm_log.txt"

struct App {
    int pid;
    time_t last_heartbeat;
};

struct App registered_apps[MAX_APPS];
int num_apps = 0;

void log_event(const char *event) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }
    time_t current_time;
    time(&current_time);
    fprintf(log_file, "[%s] %s\n", strtok(ctime(&current_time), "\n"), event);
    fclose(log_file);
}

void handle_signal(int sig) {
    // Handle signals here
    switch(sig) {
        case SIGTERM:
        case SIGINT:
            log_event("Daemon stopped.");
            exit(0);
            break;
    }
}

void process_message(char *message) {
    char *token = strtok(message, " ");
    if (token == NULL) {
        fprintf(stderr, "Invalid message format\n");
        return;
    }

    if (strcmp(token, "REGISTER") == 0) {
        token = strtok(NULL, " ");
        int pid = atoi(token);
        registered_apps[num_apps].pid = pid;
        registered_apps[num_apps].last_heartbeat = time(NULL);
        num_apps++;
        log_event("Application registered.");
    } else if (strcmp(token, "HEARTBEAT") == 0) {
        token = strtok(NULL, " ");
        int pid = atoi(token);
        for (int i = 0; i < num_apps; i++) {
            if (registered_apps[i].pid == pid) {
                registered_apps[i].last_heartbeat = time(NULL);
                break;
            }
        }
    } else if (strcmp(token, "CANCEL") == 0) {
        token = strtok(NULL, " ");
        int pid = atoi(token);
        for (int i = 0; i < num_apps; i++) {
            if (registered_apps[i].pid == pid) {
                // Implement cancellation logic
                // For now, just log the event
                log_event("Application monitoring canceled.");
                break;
            }
        }
    } else {
        fprintf(stderr, "Unknown message received\n");
    }
}

int main() {
    // Initialize FIFO
    mkfifo(FIFO_NAME, 0666);

    // Open FIFO for reading
    int fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Error opening FIFO");
        exit(1);
    }

    // Register signal handlers
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);

    log_event("Daemon started.");

    // Main daemon loop
    while(1) {
        char buffer[100];
        int bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            process_message(buffer);
        }
    }

    // Close FIFO
    close(fd);
    unlink(FIFO_NAME);

    return 0;
}

