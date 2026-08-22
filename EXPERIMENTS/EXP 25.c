#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    int fd;
    struct stat file;
    struct dirent *entry;
    DIR *dir;

    // Open file
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    write(fd, "Hello UNIX", 10);

    // fcntl
    fcntl(fd, F_SETFL, O_APPEND);

    // lseek
    lseek(fd, 0, SEEK_SET);

    // stat
    stat("sample.txt", &file);

    printf("File Size: %ld bytes\n", file.st_size);

    close(fd);

    // Open directory
    dir = opendir(".");

    printf("\nFiles in Current Directory:\n");

    // Read directory
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}
