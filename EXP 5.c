#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int bt[10], pr[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time and Priority:\n");
    for(i = 0; i < n; i++)
        scanf("%d%d", &bt[i], &pr[i]);

    // Sort according to priority
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(pr[i] > pr[j])
            {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }

    wt[0] = 0;

    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    printf("\nBT\tPriority\tWT\tTAT\n");
    for(i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        printf("%d\t%d\t\t%d\t%d\n", bt[i], pr[i], wt[i], tat[i]);
    }

    return 0;
}

OUTPUT:

Enter number of processes: 4
Enter Burst Time and Priority:
5 2
3 1
8 4
6 3

BT  Priority  WT  TAT
3   1         0   3
5   2         3   8
6   3         8   14
8   4         14  22
