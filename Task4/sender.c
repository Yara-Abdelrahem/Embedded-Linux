#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define SHARED_MEMORY_NAME "/shared_buffer" // Name of the shared memory object
#define SHARED_MEMORY_SIZE 1024             // Size of the shared memory

int main() {
    int shm_fd;
    char *shared_buffer;

    // Create shared memory
    shm_fd = shm_open(SHARED_MEMORY_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Failed to create shared memory");
        return EXIT_FAILURE;
    }

    // Resize shared memory
    if (ftruncate(shm_fd, SHARED_MEMORY_SIZE) == -1) {
        perror("Failed to set shared memory size");
        return EXIT_FAILURE;
    }

    // Map shared memory
    shared_buffer = mmap(NULL, SHARED_MEMORY_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_buffer == MAP_FAILED) {
        perror("Failed to map shared memory");
        return EXIT_FAILURE;
    }

    // Initialize shared memory with an empty string
    memset(shared_buffer, 0, SHARED_MEMORY_SIZE);

    // Write strings to shared memory
    while (1) {
        printf("Enter a string (or 'bye' to quit): ");
        fgets(shared_buffer, SHARED_MEMORY_SIZE, stdin);

        // Remove trailing newline
        shared_buffer[strcspn(shared_buffer, "\n")] = '\0';

        if (strcmp(shared_buffer, "bye") == 0) {
            break; // Exit if "bye" is sent
        }

        printf("Wrote '%s' to shared memory.\n", shared_buffer);
    }

    // Unmap the shared memory
    munmap(shared_buffer, SHARED_MEMORY_SIZE);

    // Close shared memory file descriptor
    close(shm_fd);

    return 0;
}
