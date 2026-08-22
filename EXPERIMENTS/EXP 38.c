#include <stdio.h>
#include <stdlib.h>

int main()
{
    int queue[50], temp;
    int n, head, diskSize;
    int i, j;
    int totalSeek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &diskSize);

    // Sort requests
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(queue[i] > queue[j])
            {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    printf("\nSCAN Order:\n");

    // Move towards higher cylinders
    for(i = 0; i < n; i++)
    {
        if(queue[i] >= head)
        {
            printf("%d -> ", queue[i]);
            totalSeek += abs(queue[i] - head);
            head = queue[i];
        }
    }

    // Move to end of disk
    totalSeek += abs((diskSize - 1) - head);
    head = diskSize - 1;

    printf("%d -> ", head);

    // Reverse direction
    for(i = n - 1; i >= 0; i--)
    {
        if(queue[i] < head)
        {
            printf("%d -> ", queue[i]);
            totalSeek += abs(queue[i] - head);
            head = queue[i];
        }
    }

    printf("END");

    printf("\n\nTotal Seek Time = %d\n", totalSeek);

    return 0;
}
