#include <stdio.h>

int main()
{
    int block[10], process[10];
    int allocation[10];
    int nb, np, i, j, choice;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter size of each memory block:\n");
    for(i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter size of each process:\n");
    for(i = 0; i < np; i++)
        scanf("%d", &process[i]);

    printf("\n1. First Fit");
    printf("\n2. Best Fit");
    printf("\n3. Worst Fit");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    for(i = 0; i < np; i++)
        allocation[i] = -1;

    if(choice == 1)
    {
        // First Fit
        for(i = 0; i < np; i++)
        {
            for(j = 0; j < nb; j++)
            {
                if(block[j] >= process[i])
                {
                    allocation[i] = j;
                    block[j] -= process[i];
                    break;
                }
            }
        }
    }

    else if(choice == 2)
    {
        // Best Fit
        for(i = 0; i < np; i++)
        {
            int best = -1;

            for(j = 0; j < nb; j++)
            {
                if(block[j] >= process[i])
                {
                    if(best == -1 || block[j] < block[best])
                        best = j;
                }
            }

            if(best != -1)
            {
                allocation[i] = best;
                block[best] -= process[i];
            }
        }
    }

    else if(choice == 3)
    {
        // Worst Fit
        for(i = 0; i < np; i++)
        {
            int worst = -1;

            for(j = 0; j < nb; j++)
            {
                if(block[j] >= process[i])
                {
                    if(worst == -1 || block[j] > block[worst])
                        worst = j;
                }
            }

            if(worst != -1)
            {
                allocation[i] = worst;
                block[worst] -= process[i];
            }
        }
    }

    else
    {
        printf("Invalid choice");
        return 0;
    }

    printf("\nProcess\tProcess Size\tBlock Number\n");

    for(i = 0; i < np; i++)
    {
        printf("P%d\t%d\t\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

