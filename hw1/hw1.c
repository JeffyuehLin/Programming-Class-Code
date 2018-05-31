#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void substitute(char *spat, char *tpat)
{
    int slen = strlen(spat), i;
    char line[1002], *pat;
    while (fgets(line, 1002, stdin) != NULL)
    {
        while ((pat = strstr(line, spat)) != NULL)
        {
            for (i = 0; i < (pat - line); i++)
                printf("%c", line[i]);
            printf("%s", tpat);
            strcpy(line, pat + slen);
        }
        printf("%s", line);
    }
}
void lower()
{
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c >= 'A' && c <= 'Z')
            c -= 'A' - 'a';
        printf("%c", c);
    }
}
void removes()
{
    int firsts = 1, i, j = 0, len;
    char line[1002], *newline;
    while (fgets(line, 1002, stdin) != NULL)
    {
        newline = malloc((strlen(line) + 1) * sizeof(char));
        firsts = 1;
        j = 0;
        for (i = 0; i < (len = strlen(line)); i++)
        {
            if (line[i] == ' ')
            {
                if (firsts == 1)
                {
                    newline[j] = line[i];
                    j++;
                    firsts = 0;
                }
            }
            else
            {
                newline[j] = line[i];
                firsts = 1;
                j++;
            }
        }
        newline[j] = '\0';
        len = strlen(newline);
        if (newline[0] == ' ') //remove the first space
            for (i = 0; i < len - 1; i++)
                newline[i] = newline[i + 1];
        len--;
        if (newline[len - 2] == ' ') //remove the last space
        {
            newline[len - 2] = '\n';
            newline[len - 1] = '\0';
        }
        free(newline);
    }
}
void num()
{
    int i = 0;
    char line[1002];
    while (fgets(line, 1002, stdin) != NULL)
    {
        printf("%d:%s", i, line);
        i++;
    }
}
int main(int argc, char **argv)
{
    if (argc == 0)
        return 0;
    if (strcmp(argv[1], "-s") == 0)
        substitute(argv[2], argv[3]);
    else if (strcmp(argv[1], "-l") == 0)
        lower();
    else if (strcmp(argv[1], "-r") == 0)
        removes();
    else if (strcmp(argv[1], "-i") == 0)
        num();
    return 0;
}