#include <stdio.h>
#include <stdlib.h>

int main()
{
    int queue[50];
    int n, head, i;
    int totalSeek = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk requests:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nDisk Scheduling Order:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d -> ", queue[i]);

        totalSeek += abs(queue[i] - head);

        head = queue[i];
    }

    printf("END");

    printf("\n\nTotal Seek Time = %d\n", totalSeek);

    return 0;
}

