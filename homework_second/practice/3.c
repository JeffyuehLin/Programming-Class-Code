#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int getword(char *word, int *len)
{
    int i = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (isalpha(c) > 0)
        {
            word[i] = c;
            i++;
        }
        else if (i != 0)
            break;
    }
    if (i == 0)
        return 0;
    word[i] = '\0';
    *len = i;
    return 1;
}
int main()
{
    char word[10000], maxword[10000];
    int maxlen = 0, len;
    while (getword(word, &len) != 0)
        if (len > maxlen)
        {
            strcpy(maxword, word);
            maxlen = len;
        }
    printf("%s\n", maxword);
    return 0;
}