#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct string
{
    char word[101];
    int count;
    struct string *next;
} string;
void counting(string *ptr, char *line) //search the word is exists or not
{
    string *new = malloc(sizeof(string));
    while (ptr != NULL) //if the word is exists, count++
    {
        if (strcmp(ptr->word, line) == 0)
        {
            ptr->count++;
            return;
        }
        else if (ptr->next == NULL)
            break;
        ptr = ptr->next;
    }
    strcpy(new->word, line); //if the word is not exists, malloc a new struct
    new->count = 1;
    ptr->next = new;
    new->next = NULL;
}
string *search(string *start, string *ptr) //search the previous node
{
    while (start->next != ptr)
        start = start->next;
    return start;
}
void list(string *ptr)
{
    while (ptr != NULL)
    {
        printf("%d %s\n", ptr->count, ptr->word);
        ptr = ptr->next;
    }
}
void sortandlist(string *start) //use insert sort and list
{
    string *compare = start->next, *cur, *pre, *ptr, *pre_ptr;
    while (compare != NULL)
    {
        cur = compare; //compare is the current node, to control the step
        ptr = start;
        while (ptr != cur) //ptr is to compare with cur
        {
            if (ptr == start && ((cur->count > ptr->count) || (cur->count == ptr->count && strcmp(cur->word, ptr->word) < 0)))
            { //insert the cur in front of the start
                compare = compare->next;
                pre = search(start, cur);
                pre->next = cur->next;
                cur->next = start;
                start = cur;
                break;
            }
            else if (ptr != start && ((cur->count > ptr->count) || (cur->count == ptr->count && strcmp(cur->word, ptr->word) < 0)))
            { //insert the cur in front of the ptr
                compare = compare->next;
                pre = search(start, cur);
                pre->next = cur->next;
                pre_ptr = search(start, ptr);
                pre_ptr->next = cur;
                cur->next = ptr;
                break;
            }
            ptr = ptr->next;
        }
        if (ptr == cur)
            compare = compare->next;
    }
    list(start);
}
int main()
{
    string *start = malloc(sizeof(string));
    char line[101];
    if (scanf("%s", line) == EOF)
        return 0;
    strcpy(start->word, line);
    start->count = 1;
    start->next = NULL;
    while (scanf("%s", line) != EOF)
        counting(start, line);
    sortandlist(start);
    return 0;
}