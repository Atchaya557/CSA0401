#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024   // Size of the shared memory segment

int main()
{
    key_t key = ftok("shmfile", 65);   // Generate a unique key

    // Create a new shared memory segment
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid == -1)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment
    char *shm_ptr = (char *)shmat(shmid, NULL, 0);

    if (shm_ptr == (char *)(-1))
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Write data to shared memory
    strcpy(shm_ptr, "Hello, shared memory!");

    printf("Data written to shared memory: %s\n", shm_ptr);

    // Detach shared memory
    if (shmdt(shm_ptr) == -1)
    {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Remove shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}

OUTPUT

Data written to shared memory: Hello, shared memory!
