#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data
{
    int num;
    struct data *next;
} Data;
Data *insert(int n, Data *start)
{
    Data *new = malloc(sizeof(Data));
    new->num = n;
    new->next = start;
    return new;
}
int ave(Data *start)
{
    int ave = 0, total = 0;
    while (start != NULL)
    {
        total++;
        ave = (ave * (total - 1) + start->num) / total;
        start = start->next;
    }
    return ave;
}
int main()
{
    Data *start = NULL;
    char line[100];
    int number;
    while (fgets(line, 100, stdin) != NULL)
    {
        number = atoi(line);
        start = insert(number, start);
    }
    printf("%d\n", ave(start));
    return 0;
}