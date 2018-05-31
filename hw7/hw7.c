#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#define MaxLine 6
#define MaxData 10000000
typedef struct data
{
    int num;
    char line[1010];
} Data;
void help()
{
    printf("-n:Numeral comparison\n");
    printf("-a:Random number/string generator\n");
    printf("-h:Help usage\n");
}
int mycmp(const void *a, const void *b)
{
    return (strcmp(*(char **)a, *(char **)b));
}
void numeral_sortandprint(Data *arr, int total)
{
    int i, j, k, tmpi;
    char tmpa[1002];
    for (i = 0; i < total - 1; i++)
        for (j = 0; j < total - 1 - i; j++)
            if (arr[j].num > arr[j + 1].num)
            {
                strcpy(tmpa, arr[j].line);
                strcpy(arr[j].line, arr[j + 1].line);
                strcpy(arr[j + 1].line, tmpa);
                tmpi = arr[j].num;
                arr[j].num = arr[j + 1].num;
                arr[j + 1].num = tmpi;
            }
    for (i = 0; i < total && arr[i].num == 0; i++)
        continue;
    for (j = 0; j < i - 1; j++)
        for (k = 0; k < i - 1 - j; k++)
            if (strcmp(arr[k].line, arr[k + 1].line) > 0)
            {
                strcpy(tmpa, arr[k].line);
                strcpy(arr[k].line, arr[k + 1].line);
                strcpy(arr[k + 1].line, tmpa);
            }
    for (i = 0; i < total; i++)
        printf("%s", arr[i].line);
}
void numeral(char *filename)
{
    FILE *ftr;
    char line[1000][1002];
    int i = 0, j, total, len;
    Data *arr;
    if ((ftr = fopen(filename, "r")) == NULL)
        ftr = stdin;
    while (fgets(line[i], 1002, ftr) != NULL)
        i++;
    total = i;
    arr = malloc(sizeof(Data) * total);
    for (i = 0; i < total; i++)
    {
        strcpy(arr[i].line, line[i]);
        for (j = 0; j < (len = strlen(line[i])) && isdigit(line[i][j]) == 0; j++)
            continue;
        arr[i].num = atoi(line[i] + j);
    }
    numeral_sortandprint(arr, total);
    free(arr);
    fclose(ftr);
}
void merge_sort_recursive(char **arr, char **reg, int start, int end)
{
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = strcmp(arr[start1], arr[start2]) < 0 ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}
void merge_sort(char **arr)
{
    char **reg = malloc(MaxData * sizeof(char *));
    merge_sort_recursive(arr, reg, 0, MaxData - 1);
    free(reg);
}
void autosort()
{
    int i, j, len, c, q_diff, m_diff;
    char **arr = malloc(sizeof(char *) * MaxData), **brr = malloc(sizeof(char *) * MaxData);
    struct timeval start, end;
    srand(time(NULL));
    for (i = 0; i < MaxData; i++)
    {
        len = rand() % MaxLine + 1;
        arr[i] = malloc((len + 1) * sizeof(char));
        brr[i] = arr[i];
        for (j = 0; j < len; j++)
        {
            c = rand() % 52;
            if (c <= 25)
                arr[i][j] = c + 'A';
            else
                arr[i][j] = c - 26 + 'a';
        }
        arr[i][j] = '\0';
    }
    gettimeofday(&start, NULL);
    merge_sort(brr);
    gettimeofday(&end, NULL);
    m_diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    gettimeofday(&start, NULL);
    qsort(arr, MaxData, sizeof(arr[0]), mycmp);
    gettimeofday(&end, NULL);
    q_diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    for (i = 0; i < MaxData; i++)
        printf("%s\n", arr[i]);
    printf("Merge Sort:%dms\n", m_diff /= 1000);
    printf("Q Sort:%dms\n", q_diff /= 1000);
    printf("時間差:%dms\n", m_diff - q_diff);
    free(arr);
    free(brr);
}
int main(int argc, char **argv)
{
    if (argc == 1 || strcmp(argv[1], "-n") == 0)
    {
        if (argc == 3)
            numeral(argv[2]);
        else
            numeral("");
    }
    else if (strcmp(argv[1], "-h") == 0)
        help();
    else if (strcmp(argv[1], "-a") == 0)
        autosort();
    return 0;
}