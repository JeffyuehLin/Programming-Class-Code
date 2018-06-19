#include <stdio.h>
char *mystrstr(char *line, char *pat)
{
    char *ptr = pat;
    while (*ptr != '\0' && *line != '\0')
    {
        if (*line == *ptr)
        {
            line++;
            ptr++;
        }
        else if (ptr != pat)
            ptr = pat;
        else
            line++;
    }
    return line - (ptr - pat);
}
int main(int argc, char *argv[])
{
    char line[10000];
    if (argc == 0)
        return 0;
    while (fgets(line, 10000, stdin) != NULL)
        printf("%s", mystrstr(line, argv[1]));
    return 0;
}