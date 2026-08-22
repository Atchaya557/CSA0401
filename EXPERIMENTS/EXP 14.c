#include <stdio.h>
#include <string.h>

int main()
{
    char files[20][50];
    int n, i;
    char search[50];
    int found = 0;

    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("Enter file names:\n");

    for(i = 0; i < n; i++)
        scanf("%s", files[i]);

    printf("\nFiles in Single Level Directory:\n");

    for(i = 0; i < n; i++)
        printf("%s\n", files[i]);

    printf("\nEnter file name to search: ");
    scanf("%s", search);

    for(i = 0; i < n; i++)
    {
        if(strcmp(files[i], search) == 0)
        {
            found = 1;
            break;
        }
    }

    if(found)
        printf("File found\n");
    else
        printf("File not found\n");

    return 0;
}

EXAMPLE:'

  Enter number of files: 3
Enter file names:
file1.txt
file2.txt
file3.txt

Files in Single Level Directory:
file1.txt
file2.txt
file3.txt
