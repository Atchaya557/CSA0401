#include <stdio.h>
int main(){
    int n, i, tq, time = 0;
    int bt[10], rem[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while(1)
    {
        int done = 1;

        for(i = 0; i < n; i++)
        {
            if(rem[i] > 0)
            {
                done = 0;

                if(rem[i] > tq)
                {
                    time += tq;
                    rem[i] -= tq;
                }
                else
                {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }

        if(done)
            break;
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    return 0;
}

OUTPUT:

Enter number of processes: 3
Enter Burst Time:
10
5
8
Enter Time Quantum: 2

Process BT  WT  TAT
P1      10  13  23
P2      5   10  15
P3      8   13  21
