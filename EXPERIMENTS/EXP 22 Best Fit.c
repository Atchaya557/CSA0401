#include <stdio.h>

int main() {
    int blockSize[20], processSize[20];
    int allocation[20];
    int m, n, i, j, bestIdx;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter the size of each memory blocks:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the size of each process:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    // Initialize allocation array
    for(i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Best Fit Allocation
    for(i = 0; i < n; i++) {
        bestIdx = -1;

        for(j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                if(bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        if(bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;

INPUT:

Enter the number of memory blocks: 5
Enter the size of each memory blocks:
100
500
200
300
600
Enter the number of processes: 4
Enter the size of each process:
212
417
112
426

OUTPUT:

Process No.    Process Size    Block No.
1              212             4
2              417             2
3              112             3
4              426             5
}
