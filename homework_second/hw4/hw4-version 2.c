#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct string
{
    char word[101];
    int count;
    struct string *next;
} string;
int counting(string *ptr, char *line, int total) //search the word is exists or not
{
    string *new = malloc(sizeof(string));
    while (ptr != NULL) //if the word is exists, count++
    {
        if (strcmp(ptr->word, line) == 0)
        {
            ptr->count++;
            return total;
        }
        else if (ptr->next == NULL)
            break;
        ptr = ptr->next;
    }
    strcpy(new->word, line); //if the word is not exists, malloc a new struct
    new->count = 1;
    ptr->next = new;
    new->next = NULL;
    return (total + 1);
}
void sortandlist(string *start, int total)
{
    string **s = malloc(sizeof(string *) * total), *tmp;
    int i, j;
    for (i = 0; i < total; i++)
    {
        s[i] = start;
        start = start->next;
    }
    for (i = 0; i < total - 1; i++)
        for (j = 0; j < total - 1 - i; j++)
        {
            if (s[j]->count < s[j + 1]->count)
            {
                tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
            else if (s[j]->count == s[j + 1]->count && strcmp(s[j]->word, s[j + 1]->word) > 0)
            {
                tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    for (i = 0; i < total; i++)
        printf("%d %s\n", s[i]->count, s[i]->word);
}
int main()
{
    string *start = malloc(sizeof(string));
    char line[101];
    int total = 1;
    if (scanf("%s", line) == EOF)
        return 0;
    strcpy(start->word, line);
    start->count = 1;
    start->next = NULL;
    while (scanf("%s", line) != EOF)
        total = counting(start, line, total);
    sortandlist(start, total);
    return 0;
}