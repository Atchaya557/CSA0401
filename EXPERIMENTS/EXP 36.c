#include <stdio.h>

int main()
{
    int blocks[50];
    int n, i;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("\nLinked Allocation:\n");

    for(i = 0; i < n - 1; i++)
    {
        printf("%d -> ", blocks[i]);
    }

    printf("%d -> NULL\n", blocks[n - 1]);

    return 0;
}

OUTPUT:

10 -> 25 -> 7 -> 40 -> NULL
