#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxwordlen 55
#define Maxlinelen 10000
#define Maxkey 701
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
    unsigned long long key = 0;
    while (word++ && *word != '\0')
        key = key * 33 + abs(*word);
    return key % Maxkey;
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
    char word[Maxwordlen];
    while (fscanf(ftr, "%s", word) != EOF)
    {
        key = hashfunction(word);
        t[key].start = inserthash(t[key].start, word);
    }
    fclose(ftr);
}
int getword(char *line, char *word, int len) //取得一個長度為len的詞
{
    int i;
    for (i = 0; i < len && *line != '\0'; i++)
    {
        *word = *line;
        word++;
        line++;
    }
    *word = '\0';
    return i;
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
    char line[Maxlinelen], word[Maxwordlen], *ptr;
    int i, wordlen;
    while (fgets(line, Maxlinelen, ftr) != NULL)
    {
        if ((ptr = strchr(line, '\n')) != NULL) //去行尾空白
            *ptr = '\0';
        ptr = line;
        while (*ptr != '\0')
        {
            for (i = Maxwordlen; i > 1 && *ptr != '\0'; i--) //從最長的長度開始搜尋
            {
                if ((wordlen = getword(ptr, word, i)) < i && i == Maxwordlen) //如果取得的長度小於Maxwordlen
                    i = wordlen;                                              //則把i設為該長度，以加快斷詞的效率
                if (search(t[hashfunction(word)].start, word))                //搜尋該字串有沒有出現在字典裡
                {
                    printf("%s\n", word);
                    break;
                }
            }
            if (i == 1) //如果沒找到，就直接印出該字
            {
                wordlen = getword(ptr, word, 1);
                printf("%s\n", word);
            }
            ptr += i; //把ptr往後移
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