#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void selectsort(int total, char **line)
{ //sort the strings
    int i, j, max = 0;
    char *tmp;
    for (i = 0; i < total - 1; i++)
    {
        for (j = 0, max = 0; j < total - i; j++)
            if (strcmp(line[max], line[j]) < 0)
                max = j;
        tmp = line[max];
        line[max] = line[total - 1 - i];
        line[total - 1 - i] = tmp;
    }
}
int main(void)
{
    char *line[1003], input[1003];
    int i = 0, total;
    while (fgets(input, 1003, stdin))
    {
        line[i] = malloc((strlen(input) + 1) * sizeof(char));
        strcpy(line[i], input);
        i++;
    }
    total = i;
    selectsort(total, line);
    for (i = 0; i < total; i++)
        printf("%s", line[i]);
    return 0;
}
