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

    // Open the existing shared memory
    shm_fd = shm_open(SHARED_MEMORY_NAME, O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Failed to open shared memory");
        return EXIT_FAILURE;
    }

    // Map shared memory
    shared_buffer = mmap(NULL, SHARED_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_buffer == MAP_FAILED) {
        perror("Failed to map shared memory");
        return EXIT_FAILURE;
    }

    // Continuously read from shared memory
    while (1) {
        // Check if the shared memory contains data
        if (strlen(shared_buffer) > 0) {
            printf("Read '%s'hared memory.\n", shared_buffer);

            if (strcmp(shared_buffer, "bye") == 0) {
                break; // Exit if "bye" is received
            }

            // Clear the shared buffer after reading
            memset(shared_buffer, 0, SHARED_MEMORY_SIZE);
        }
    }

    // Unmap the shared memory
    munmap(shared_buffer, SHARED_MEMORY_SIZE);

    // Close shared memory file descriptor
    close(shm_fd);

    // Remove the shared memory (cleanup)
    shm_unlink(SHARED_MEMORY_NAME);

    return 0;
}
