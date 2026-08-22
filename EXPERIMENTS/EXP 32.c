#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f, i, j;
    int pageFaults = 0;
    int found, least, index;

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
                least = i;
                index = -1;

                for(j = 0; j < f; j++)
                {
                    int k;

                    for(k = i - 1; k >= 0; k--)
                    {
                        if(pages[k] == frames[j])
                            break;
                    }

                    if(k < least)
                    {
                        least = k;
                        index = j;
                    }
                }

                frames[index] = pages[i];
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
