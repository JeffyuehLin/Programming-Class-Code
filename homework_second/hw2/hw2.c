#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student
{
    int id;
    char name[20], phone[20], email[20];
} student;
int search(student *s, int id, int total) //search the id is exists or not
{
    int i;
    for (i = 0; i < total; i++)
        if (s[i].id == id)
            return i; //if the id is exists, return the student number
    return -1;        //if the id is not exists, return -1
}
void inputstudentid(int *id, char *line) //get the id from the line
{
    line += 12;
    *id = atoi(line);
}
void inputstudent(student *s, char *line) //get the information from the line
{
    int i;
    line = strstr(line, "name:") + 5;
    for (i = 0; line[i] != '\t'; i++)
        s->name[i] = line[i];
    s->name[i] = '\0';
    line = strstr(line, "phone:") + 6;
    for (i = 0; line[i] != '\t'; i++)
        s->phone[i] = line[i];
    s->phone[i] = '\0';
    line = strstr(line, "email:") + 6;
    for (i = 0; line[i] != '\n'; i++)
        s->email[i] = line[i];
    s->email[i] = '\0';
}
void insert(student *s, char *line, int *total) //insert the new data
{
    (*total)++;
    inputstudentid(&(s[*total - 1].id), line);
    if (search(s, s[*total - 1].id, *total - 1) != -1)
    {
        printf("Insert error! studentID is exists!\n");
        (*total)--;
        return;
    }
    inputstudent(&s[*total - 1], line);
    printf("Insert successful!\n");
}
void delete (student *s, char *line, int *total) //delete the past data
{
    int num, id, i;
    inputstudentid(&id, line);
    if ((num = search(s, id, *total)) == -1)
    {
        printf("Delete error! studentID not exists!\n");
        return;
    }
    for (i = num; i < *total - 1; i++)
        s[i] = s[i + 1];
    (*total)--;
    printf("delete successful!\n");
}
void update(student *s, char *line, int total) //update the past data
{
    int num, id;
    inputstudentid(&id, line);
    if ((num = search(s, id, total)) == -1)
    {
        printf("Update error! studentID not exists!\n");
        return;
    }
    s[num].id = id;
    inputstudent(&s[num], line);
    printf("Update successful!\n");
}
void find(student *s, char *pat, int total)
{
    int i, flag = 0;
    pat[strlen(pat) - 1] = '\0'; //remove '\n'
    for (i = 0; i < total; i++)
        if (strstr(s[i].name, pat) != NULL || strstr(s[i].phone, pat) != NULL || strstr(s[i].email, pat) != NULL)
        {
            printf("studentID:%d\tname:%s\tphone:%s\temail:%s\n", s[i].id, s[i].name, s[i].phone, s[i].email);
            flag = 1;
        }
    if (flag == 0)
        printf("Find error! Not exists!\n");
}
void list(student *s, int total) //list the all data
{
    int i;
    for (i = 0; i < total; i++)
        printf("studentID:%d\tname:%s\tphone:%s\temail:%s\n", s[i].id, s[i].name, s[i].phone, s[i].email);
}
int main()
{
    student s[100];
    char line[100];
    int total = 0;
    printf("Please input command(i/d/u/f/l/q) and data :\n");
    printf("Insert the record : i studentID\\tname\\tphone\\temail\n");
    printf("Delete the record : d studentID\n");
    printf("Update the record : u studentID\\tname\\tphone\\temail\n");
    printf("Find the record : f [string]\n");
    printf("List the record : l\n");
    printf("Quit : q\n");
    while (fgets(line, 100, stdin) != NULL)
    {
        if (line[0] == 'i')
            insert(s, line, &total);
        else if (line[0] == 'd')
            delete (s, line, &total);
        else if (line[0] == 'u')
            update(s, line, total);
        else if (line[0] == 'f')
            find(s, line + 2, total);
        else if (line[0] == 'l')
            list(s, total);
        else if (line[0] == 'q')
            break;
    }
    printf("Thanks for your using!\n");
    return 0;
}