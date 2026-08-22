#include <stdio.h>

int main()
{
    int start, length, i;

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter number of blocks: ");
    scanf("%d", &length);

    printf("\nFile blocks are:\n");

    for(i = 0; i < length; i++)
    {
        printf("%d ", start + i);
    }

    return 0;
}
