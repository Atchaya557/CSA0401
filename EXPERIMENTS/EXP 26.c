#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];

    // Create file
    fd = open("file.txt", O_CREAT | O_RDWR, 0644);

    printf("File created successfully\n");

    // Write
    write(fd, "Operating System", 16);

    printf("Data written successfully\n");

    // Move pointer to beginning
    lseek(fd, 0, SEEK_SET);

    // Read
    read(fd, buffer, 16);

    buffer[16] = '\0';

    printf("File Content: %s\n", buffer);

    close(fd);

    // Delete file
    unlink("file.txt");

    printf("File deleted successfully\n");

    return 0;
}

OUTPUT:
File created successfully
Data written successfully
File Content: Operating System
File deleted successfully
