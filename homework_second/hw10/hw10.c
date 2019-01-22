#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Onewordsize 2 //Big5
#define Maxwordlen 17
#define Maxlinelen 10000
#define Maxkey 120
typedef struct hashlist
{
    char *word;
    struct hashlist *next;
} Hashlist;
typedef struct hashtable
{
    Hashlist *start;
} Hashtable;
int hashfunction(char *word) //取得hash的key
{
    int i, key = 0;
    for (i = 0; i < Onewordsize; i++)
        key += word[i];
    key = abs(key) % Maxkey;
    return key;
}
Hashlist *inserthash(Hashlist *start, char *word) //把新資料存入hash中，插在Linked List的始節點
{
    Hashlist *new = malloc(sizeof(Hashlist));
    new->word = strdup(word);
    new->next = start;
    return new;
}
void createhashtable(FILE *ftr, Hashtable *t) //新建一個Hash Table，把字典資料存入
{
    int key;
    char word[Maxwordlen * Onewordsize];
    while (fscanf(ftr, "%s", word) != EOF)
    {
        key = hashfunction(word);
        t[key].start = inserthash(t[key].start, word);
    }
    fclose(ftr);
}
void getword(char *ptr, char *word, int len) //取得一個長度為len的詞
{
    len *= Onewordsize;
    while (len-- && *ptr != '\0')
    {
        *word = *ptr;
        word++;
        ptr++;
    }
    *word = '\0';
}
int search(Hashlist *ptr, char *word) //搜尋是否有該詞
{
    while (ptr != NULL)
    {
        if (strcmp(ptr->word, word) == 0)
            return 1;
        ptr = ptr->next;
    }
    return 0;
}
void cutline(FILE *ftr, Hashtable *t) //斷詞
{
    char line[Maxlinelen], word[Maxwordlen * Onewordsize], *ptr;
    int i;
    while (fgets(line, Maxlinelen, ftr) != NULL)
    {
        if ((ptr = strchr(line, '\n')) != NULL) //去行尾空白
            *ptr = '\0';
        ptr = line;
        while (*ptr != '\0')
        {
            for (i = Maxwordlen; i > 1 && *ptr != '\0'; i--) //從最長的長度開始搜尋
            {
                getword(ptr, word, i);
                if (search(t[hashfunction(word)].start, word))
                {
                    printf("%s\n", word);
                    ptr += (i * Onewordsize); //把ptr往後移
                    break;
                }
            }
            if (i == 1) //如果沒找到，就直接印出該字
            {
                getword(ptr, word, 1);
                if (strlen(word) <= 1) //如果長度小於1，就不印
                    break;
                printf("%s\n", word);
                ptr += Onewordsize;
            }
        }
    }
}
int main(int argc, char **argv)
{
    Hashtable hashtable[Maxkey];
    FILE *dic, *inftr;
    dic = fopen(argv[1], "r");
    if (argc != 0 && (inftr = fopen(argv[2], "r")) == NULL)
        inftr = stdin;
    memset(hashtable, 0, sizeof(hashtable)); //把每個Linked List的始節點設為NULL
    createhashtable(dic, hashtable);
    cutline(inftr, hashtable);
    fclose(inftr);
    return 0;
}