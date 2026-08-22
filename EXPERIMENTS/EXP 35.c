#include <stdio.h>

int main()
{
    int indexBlock, n, blocks[50];
    int i;

    printf("Enter index block number: ");
    scanf("%d", &indexBlock);

    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    printf("Enter file block numbers:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("\nIndex Block: %d\n", indexBlock);

    printf("File Blocks:\n");

    for(i = 0; i < n; i++)
        printf("Block %d -> %d\n", i, blocks[i]);

    return 0;
}
