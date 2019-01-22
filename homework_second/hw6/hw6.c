#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct hash
{
    int count;
    char word[100];
    struct hash *next;
} Hash;
typedef struct hashtable
{
    char key;
    Hash *start; //存每一條Linked List的第一個位置
} Table;
int hashfuction(Table *t, char a, int total) //取得Hash Table的key(以詞的第一個字來判斷)
{
    int i;
    for (i = 0; i < total; i++)
    {
        if (a == t[i].key)
            return i;
    }
    return -1;
}
Hash *inputitem(char *line) //新增一個節點，並回傳該節點位置
{
    Hash *new = malloc(sizeof(Hash));
    strcpy(new->word, line);
    new->count = 1;
    new->next = NULL;
    return new;
}
int search(Hash *ptr, Hash **fptr, char *line) //搜尋Linked List裡面有沒有相同的字
{
    while (ptr != NULL)
    {
        if (strcmp(ptr->word, line) == 0) //如找到一樣的，讓fptr存取當下的位置
        {
            *fptr = ptr;
            return 1; //找到就會傳1
        }
        else if (ptr->next == NULL) //如果沒有，讓fptr存取最後一個位置
        {
            *fptr = ptr;
            return 0; //沒找到就回傳0
        }
        ptr = ptr->next;
    }
    return 0;
}
void insertlist(Hash *ptr, char *line) //處理新增的資料
{
    Hash *fptr = NULL;
    if (search(ptr, &fptr, line) == 1) //如果有找到，count++
        fptr->count++;
    else
        fptr->next = inputitem(line); //如果沒找到，把新的節點連接到最後
}
void insert(Table *t, char *line, int *total) //插入新的資料
{
    int key;
    line += 7;
    line[strlen(line) - 1] = '\0';
    key = hashfuction(t, line[0], *total); //取得hash table的key
    if (key != -1)
        insertlist(t[key].start, line);
    else //如果table裡沒有該類型的key，則新增一個table在最後面
    {
        t[*total].start = inputitem(line);
        t[*total].key = line[0];
        (*total)++;
    }
}
void delete (Table *t, char *line, int *total) //找到相同的點，並count--
{
    int key;
    Hash *fptr = NULL;
    line += 7;
    line[strlen(line) - 1] = '\0';
    key = hashfuction(t, line[0], *total);
    if (key == -1 || search(t[key].start, &fptr, line) == 0)
        return;
    fptr->count--;
}
void query(Table *t, char *line, int total) //搜尋資料
{
    int key;
    Hash *fptr = NULL;
    line += 6;
    line[strlen(line) - 1] = '\0';
    key = hashfuction(t, line[0], total);
    if (key == -1 || search(t[key].start, &fptr, line) == 0) //如果沒找到，輸出Not found!
        printf("Not found!\n");
    else
        printf("%s\t%d\n", fptr->word, fptr->count);
}
int inputarry(Table *t, Hash **a, int total) //存取每個節點到陣列裡
{
    int i, j = 0;
    Hash *ptr;
    for (i = 0; i < total; i++)
    {
        ptr = t[i].start;
        while (ptr != NULL)
        {
            a[j] = ptr;
            j++;
            ptr = ptr->next;
        }
    }
    return j; //回傳節點的總數
}
void count(Table *t, int total) //依count大小來排序
{
    int i, j;
    Hash *a[1000], *tmp;
    total = inputarry(t, a, total);
    for (i = 0; i < total - 1; i++) //bubble sort
        for (j = 0; j < total - 1 - i; j++)
            if (a[j]->count < a[j + 1]->count || (a[j]->count == a[j + 1]->count && strcmp(a[j]->word, a[j + 1]->word) > 0))
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
    for (i = 0; i < total; i++)
        printf("%d\t%s\n", a[i]->count, a[i]->word);
}
int main()
{
    char line[1000], *ptr;
    int total = 0;
    Table table[55];
    while (fgets(line, 1000, stdin) != NULL)
    {
        if ((ptr = strstr(line, "insert")) != NULL)
            insert(table, line, &total);
        else if ((ptr = strstr(line, "delete")) != NULL)
            delete (table, line, &total);
        else if ((ptr = strstr(line, "query")) != NULL)
        {
            printf("----------\n");
            query(table, line, total);
            printf("----------\n");
        }
        else if ((ptr = strstr(line, "count")) != NULL)
        {
            printf("----------\n");
            count(table, total);
            printf("----------\n");
        }
    }
    return 0;
}