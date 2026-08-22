#include <stdio.h>
#include <string.h>

int main()
{
    char users[10][30];
    char files[10][10][30];
    int usersCount, fileCount[10];
    int i, j;

    printf("Enter number of users: ");
    scanf("%d", &usersCount);

    for(i = 0; i < usersCount; i++)
    {
        printf("\nEnter user name: ");
        scanf("%s", users[i]);

        printf("Enter number of files for %s: ", users[i]);
        scanf("%d", &fileCount[i]);

        printf("Enter file names:\n");

        for(j = 0; j < fileCount[i]; j++)
        {
            scanf("%s", files[i][j]);
        }
    }

    printf("\n--- Two Level Directory ---\n");

    for(i = 0; i < usersCount; i++)
    {
        printf("\nUser Directory: %s\n", users[i]);

        for(j = 0; j < fileCount[i]; j++)
        {
            printf("   %s\n", files[i][j]);
        }
    }

    return 0;
}
