#include <stdio.h>
#include <unistd.h>

int main()
{
    fork();

    printf("Process ID (PID): %d\n", getpid());
    printf("Parent Process ID (PPID): %d\n", getppid());

    return 0;
}

OUTPUT:

Process ID (PID): 3256
Parent Process ID (PPID): 2100
