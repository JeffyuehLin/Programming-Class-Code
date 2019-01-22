#include <stdio.h>
char *getword(char *arr, int m, int n)
{
    char word[1002];
    int i, j;
    for (i = m, j = 0; i < n; i++, j++)
        word[j] = arr[i];
    word[j] = '\0';
    for (i = 0; i <= j; i++)
        arr[i] = word[i];
    return arr;
}
int mystrcmp(char *arr, char *brr)
{
    while (*arr == *brr && *arr != '\0' && *brr != '\0')
    {
        arr++;
        brr++;
    }
    return *arr - *brr;
}
int main()
{
    int m, n, a, b;
    char arr[1002], brr[1002];
    while (scanf("%s %d %d %s %d %d", arr, &m, &n, brr, &a, &b) != EOF)
    {
        printf("%s\n", getword(arr, m, n));
        printf("%s\n", getword(brr, a, b));
        printf("%d\n", mystrcmp(arr, brr));
    }
    return 0;
}