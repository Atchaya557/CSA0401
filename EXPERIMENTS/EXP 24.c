#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];

    // Create and open file
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Write into file
    write(fd, "Hello UNIX System Calls", 24);

    // Move file pointer to beginning
    lseek(fd, 0, SEEK_SET);

    // Read from file
    read(fd, buffer, sizeof(buffer) - 1);

    buffer[24] = '\0';

    printf("File Content: %s\n", buffer);

    // Close file
    close(fd);

    return 0;
}
