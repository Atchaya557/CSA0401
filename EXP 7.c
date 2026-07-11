#include <stdio.h>
int main(){
    int n, i, j, temp;
    int bt[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }

    wt[0] = 0;

    for(i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    printf("\nBT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        printf("%d\t%d\t%d\n", bt[i], wt[i], tat[i]);
    }

    return 0;
}

OUTPUT:

Enter number of processes: 4
Enter Burst Time:
6
8
7
3

BT   WT   TAT
3    0    3
6    3    9
7    9    16
8    16   24
