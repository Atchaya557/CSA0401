#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void print_permissions(mode_t mode) {
    printf("User/Owner  : %c%c%c\n",
           (mode & S_IRUSR) ? 'r' : '-',
           (mode & S_IWUSR) ? 'w' : '-',
           (mode & S_IXUSR) ? 'x' : '-');

    printf("Group       : %c%c%c\n",
           (mode & S_IRGRP) ? 'r' : '-',
           (mode & S_IWGRP) ? 'w' : '-',
           (mode & S_IXGRP) ? 'x' : '-');

    printf("Others      : %c%c%c\n",
           (mode & S_IROTH) ? 'r' : '-',
           (mode & S_IWOTH) ? 'w' : '-',
           (mode & S_IXOTH) ? 'x' : '-');
}

int main() {
    const char *filename = "test_permission.txt";

    // 1. Create a sample file
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error creating file");
        return 1;
    }
    fputs("Linux Permission Demonstration\n", fp);
    fclose(fp);

    struct stat file_stat;

    // 2. Display default permissions
    if (stat(filename, &file_stat) == 0) {
        printf("--- Initial Permissions ---\n");
        print_permissions(file_stat.st_mode);
    }

    // 3. Change permissions using Bitwise OR (Equivalent to 0755 / rwxr-xr-x)
    // Owner: Read, Write, Execute (S_IRWXU)
    // Group: Read, Execute (S_IRGRP | S_IXGRP)
    // Others: Read, Execute (S_IROTH | S_IXOTH)
    mode_t new_mode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;

    if (chmod(filename, new_mode) == 0) {
        printf("\n--- Permissions Changed to 0755 (rwxr-xr-x) ---\n");
        if (stat(filename, &file_stat) == 0) {
            print_permissions(file_stat.st_mode);
        }
    } else {
        perror("chmod failed");
    }

    // 4. Change permissions using Octal notation directly (0640 / rw-r-----)
    if (chmod(filename, 0640) == 0) {
        printf("\n--- Permissions Changed to 0640 (rw-r-----) ---\n");
        if (stat(filename, &file_stat) == 0) {
            print_permissions(file_stat.st_mode);
        }
    }

    // Cleanup created file
    unlink(filename);
    return 0;
}

OUTPUT:

--- Initial Permissions ---
User/Owner  : rw-
Group       : rw-
Others      : r--

--- Permissions Changed to 0755 (rwxr-xr-x) ---
User/Owner  : rwx
Group       : r-x
Others      : r-x

--- Permissions Changed to 0640 (rw-r-----) ---
User/Owner  : rw-
Group       : r--
Others      : ---
