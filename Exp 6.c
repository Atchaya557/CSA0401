#include <stdio.h>
int main(){
    int i, n, tq, rem[10], bt[10], wt = 0, tat = 0;

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
                    tat += tq;
                    rem[i] -= tq;
                }
                else
                {
                    tat += rem[i];
                    wt += tat - bt[i];
                    rem[i] = 0;
                }
            }
        }
        if(done)
            break;
    }
    printf("\nAverage Waiting Time = %.2f", (float)wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)(wt + tat) / n);

    return 0;
}

OUTPUT:

Enter number of processes: 3
Enter Burst Time:
10
5
8
Enter Time Quantum: 2

Average Waiting Time = 10.33
Average Turnaround Time = 18.00
