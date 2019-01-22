//Author: Jeff.y.Lin
//Last editor:  2018/02/21
/*
    The editor's rule of the director...

    There are few items in one line:
    1. student id: the id has 9 number
    2. name: the name is less than 20 words
    3. gender: the "m" is male, the "f" is female
    3. phone number: the number is less than 15 digits
    4. e-mail address: the address is less than 30 words(included symbol)

    There is a space between two items,and a newline(\n) between two lines
    The example:
    406410038 Jeff.Lin m 0932877274 jeff4209@gmail.com(\n)

    The maximun total of lines is 1000
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct Student
{
    char id[10];
    char name[21];
    char gender[2];
    char phone[16];
    char email[31];
    void *next;
} student;
int read(student *s, FILE *fp)
{
    int i = 0, j, k; //i is the number of line,j is the word number in the line,k is the word number in the items
    char line[85];
    while (fgets(line, 85, fp) != NULL)
    {
        j = 0;
        for (k = 0; line[j] != '\t'; k++, j++)
            s[i].id[k] = line[j];
        s[i].id[k] = '\0';
        j++;
        for (k = 0; line[j] != '\t'; k++, j++)
            s[i].name[k] = line[j];
        s[i].name[k] = '\0';
        j++;
        s[i].gender[0] = line[j];
        s[i].gender[1] = '\0';
        j += 2;
        for (k = 0; line[j] != '\t'; k++, j++)
            s[i].phone[k] = line[j];
        s[i].phone[k] = '\0';
        j++;
        for (k = 0; line[j] != '\t'; k++, j++)
            s[i].email[k] = line[j];
        s[i].email[k] = '\0';

        if (i != 0)
            s[i - 1].next = &s[i];
        i++;
    }
    if (i == 0)
        s[0].next = NULL;
    else
        s[i - 1].next = NULL;
    return i;
}
void add(void *currentnext, student *new, FILE *fp)
{
    printf("Input the new id(only 9 digits):");
    scanf("%s", new->id);
    printf("Input the name(less than 20 words, without space):");
    scanf("%s", new->name);
    printf("Input the gender(m: male; f: female):");
    scanf("%s", new->gender);
    printf("Input the phone number(less than 15 digits):");
    scanf("%s", new->phone);
    printf("Input the e-mail address(less than 30 words):");
    scanf("%s", new->email);
    currentnext = new;
    if (currentnext != new)
        printf("what!!!\n");
    new->next = NULL;
    fprintf(fp, "%s\t%s\t%s\t%s\t%s\n", new->id, new->name, new->gender, new->phone, new->email);
    printf("Add success...\n");
}
void delete () {}
void edit() {}
void list(student *s)
{
    student *ptr = &s[0];
    printf("Student ID\tName\t\tGender\tPhone Number\tE-mail address\n");
    while (ptr != NULL)
    {
        printf("%s\t%s\t%s\t%s\t%s\n", ptr->id, ptr->name, ptr->gender, ptr->phone, ptr->email);
        ptr = ptr->next;
    }
}
int main()
{
    int total;
    student s[1000];
    char option[1];
    FILE *fp = fopen("director.txt", "a+");
    if (fp == NULL)
    {
        printf("Open the directory fail...\n");
        return 0;
    }
    //printf("fuck...\n");
    total = read(s, fp);
    printf("total=%d...\n", total);
    while (1)
    {
        printf("Choose the option you want to do...\n");
        printf("(a) dd:      add a new member to the director\n");
        printf("(d) elete:   remove the member from the directory\n");
        printf("(e) dit:     edit the member\n");
        printf("(l) ist:     list all members without any sort\n");
        printf("(s) ort:     sort the directory and list\n");
        printf("(g) oodbye:  leave the program\n");
        scanf("%s", option);
        if (strcmp(option, "a") == 0)
        {
            add(s[total - 1].next, &s[total], fp);
            total++;
        }
        else if (strcmp(option, "d") == 0)
            delete ();
        else if (strcmp(option, "e") == 0)
            edit();
        else if (strcmp(option, "l") == 0)
            list(s);
        else if (strcmp(option, "g") == 0)
            break;
    }
    printf("You will leave the director program...\n");
    printf("See you next time...\n");
    fclose(fp);
    return 0;
}