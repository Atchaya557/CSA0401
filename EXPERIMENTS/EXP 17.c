#include <stdio.h>

int main()
{
    int n, m, i, j;

    int allocation[10][10];
    int maximum[10][10];
    int available[10];

    int need[10][10];
    int finish[10];
    int safeSequence[10];

    int count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Maximum Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");

    for(i = 0; i < m; i++)
        scanf("%d", &available[i]);

    // Calculate Need Matrix
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    // Initialize finish array
    for(i = 0; i < n; i++)
        finish[i] = 0;

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > available[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    for(j = 0; j < m; j++)
                    {
                        available[j] += allocation[i][j];
                    }

                    safeSequence[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            printf("\nSystem is in an UNSAFE state\n");
            return 0;
        }
    }

    printf("\nSystem is in a SAFE state\n");

    printf("Safe Sequence: ");

    for(i = 0; i < n; i++)
    {
        printf("P%d", safeSequence[i]);

        if(i != n - 1)
            printf(" -> ");
    }

    printf("\n");

    return 0;
}
