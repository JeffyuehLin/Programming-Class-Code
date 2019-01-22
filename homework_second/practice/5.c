#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bubblesort(char word[1000][1002], int total)
{
    int i, j;
    char tmp[1002];
    for (i = 0; i < total - 1; i++)
        for (j = 0; j < total - 1 - i; j++)
            if (strcmp(word[j], word[j + 1]) > 0)
            {
                strcpy(tmp, word[j]);
                strcpy(word[j], word[j + 1]);
                strcpy(word[j + 1], tmp);
            }
    for (i = 0; i < total; i++)
        printf("%s", word[i]);
}
int main()
{
    char word[1000][1002];
    int i = 0;
    while (fgets(word[i], 1002, stdin) != NULL)
        i++;
    bubblesort(word, i);
}