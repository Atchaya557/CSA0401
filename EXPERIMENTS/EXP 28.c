#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char line[200];
    char word[50];

    fp = fopen("sample.txt", "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    printf("Enter word to search: ");
    scanf("%s", word);

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, word) != NULL)
        {
            printf("%s", line);
        }
    }

    fclose(fp);

    return 0;
}
SAMPLE TEXT:
Operating System
UNIX is an Operating System
Linux System

INPUT:
Operating

OUTPUT:
Operating System
UNIX is an Operating System
