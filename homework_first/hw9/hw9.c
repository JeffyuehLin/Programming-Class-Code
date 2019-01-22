#include <stdio.h>
#include <string.h>
void usage(void)
{ //if the user input the wrong option, it will appear this messege
    printf("please input a correct option\n");
    printf("-c: print pattern counts\n");
    printf("-m: find lines containing a pattern\n");
    printf("-v: find lines not containing a pattern\n");
}
int mystrstr(char *line, char *pat, int *statecount)
{                                                 //distinguish the pattern and the line
    int i = 0, j = 0, linelen, patlen, state = 0; //return state to show the line has the pattern or not
    linelen = strlen(line) - 1;                   //remove the \n
    patlen = strlen(pat);
    line[linelen] = 0; //remove the \n
    while (i < linelen)
    {
        if (pat[0] != line[i] && j == 0)
            ;
        else if (pat[j] == line[i])
        {
            if (j < patlen - 1)
                j++;
            else
            {
                (*statecount)++;
                state++;
                j = 0;
            }
        }
        else
        {
            j = 0;
            i--;
        }
        i++;
    }
    return state;
}
int main(int argc, char **argv)
{
    char line[1001];
    int statecount = 0;
    if (argc != 3 && strcmp(argv[0], "a.out") != 0)
    { //distinguish the parameters are correct
        usage();
        return 0;
    }
    else if (strcmp(argv[1], "-c") != 0 && strcmp(argv[1], "-m") != 0 && strcmp(argv[1], "-v") != 0)
    {
        usage();
        return 0;
    }
    while (fgets(line, 1001, stdin))
    {
        if (mystrstr(line, argv[2], &statecount) != 0)
        {
            if (strcmp(argv[1], "-m") == 0)
                puts(line);
        }
        else if (strcmp(argv[1], "-v") == 0)
            puts(line);
    }
    if (strcmp(argv[1], "-c") == 0)
        printf("%s: %d\n", argv[2], statecount);
    return 0;
}