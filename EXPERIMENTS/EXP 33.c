#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f, i, j, k;
    int pageFaults = 0;
    int found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            int empty = -1;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    empty = j;
                    break;
                }
            }

            if(empty != -1)
            {
                frames[empty] = pages[i];
            }
            else
            {
                int farthest = -1;
                int replaceIndex = -1;

                for(j = 0; j < f; j++)
                {
                    int nextUse = n;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frames[j] == pages[k])
                        {
                            nextUse = k;
                            break;
                        }
                    }

                    if(nextUse > farthest)
                    {
                        farthest = nextUse;
                        replaceIndex = j;
                    }
                }

                frames[replaceIndex] = pages[i];
            }

            pageFaults++;
        }

        printf("\nPage %d -> ", pages[i]);

        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
