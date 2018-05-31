#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student
{
    int id;
    char name[30], phone[30], email[30];
    struct Student *next;
} student;
int search(student *start, student **ptr, int id) //search the id's exists or not.if it is,return 1;or return 0
{
    while (1)
    {
        if (start == NULL) //if there is not any data, set the ptr = start, and return 0
        {
            *ptr = start;
            return 0; //because there is not any data to find, so return 0
        }
        else if (start->id == id)
        {
            *ptr = start; //if there is the same id, let ptr = start
            return 1;     //because the id is exists, so return 1
        }
        else if (start->next != NULL && start->next->id > id)
        {
            *ptr = start; //if the id is not exists, and between the two ids, let ptr = start
            return 0;
        }
        else if (start->next == NULL)
        {
            *ptr = start; //if the start is the last data, let ptr = start to store the last node
            return 0;     //because the id is not exists, so return 0
        }
        start = start->next; //move the start to the next node
    }
}
void inputstudentid(int *id, char *line) //get the id from the line
{
    line += 12;       //because there are 12 char before the id, so move back to the place
    *id = atoi(line); //use function "atoi" to get the id from the line
}
void inputstudent(student *ptr, char *line) //get the information from the line
{
    int i;
    line = strstr(line, "name:") + 5; //let the line[0] on the first word of the name
    for (i = 0; line[i] != '\t'; i++) //put the line[i] into ptr->name, until '\t'
        ptr->name[i] = line[i];
    ptr->name[i] = '\0';               //put '\0' in the last word of the string
    line = strstr(line, "phone:") + 6; //just like the option about name
    for (i = 0; line[i] != '\t'; i++)
        ptr->phone[i] = line[i];
    ptr->phone[i] = '\0';
    line = strstr(line, "email:") + 6;
    for (i = 0; line[i] != '\n'; i++)
        ptr->email[i] = line[i];
    ptr->email[i] = '\0';
}
void insert(student **start, student *new, char *line) //insert the new data
{
    int tmp;
    student *ptr = malloc(sizeof(student)), *s = *start;
    inputstudentid(&tmp, line);         //get the id from the line
    if (search(*start, &ptr, tmp) == 1) //find the id is exists or not, if it is exist, output insert error
    {
        printf("Insert error! studentID is exists!\n");
        return;
    }
    new = malloc(sizeof(student)); //get the new struct
    new->id = tmp;                 //put the id in the new
    inputstudent(new, line);       //put the others in the new
    if (*start == NULL)            //if the data is empty, set the start = new
        *start = new;
    else if (new->id < s->id) //if the new->id is smaller than s->id, insert the new in front of start
    {
        new->next = *start;
        *start = new;
    }
    else //insert the new between the ptr and ptr->next
    {
        new->next = ptr->next;
        ptr->next = new;
    }
    printf("Insert successful!\n");
}
void delete (student **start, char *line) //delete the past data
{
    int id;
    student *ptr, *cptr = *start;
    inputstudentid(&id, line);
    if (search(*start, &ptr, id) == 0) //if the id is not exists, print usage
    {
        printf("Delete error! studentID not exists!\n");
        return;
    }
    if (ptr == *start) //if the ptr is the start, set the start is the next one
    {
        *start = ptr->next;
        free(ptr);
    }
    else
    {
        while (cptr->next != ptr) //find the previous data
            cptr = cptr->next;
        cptr->next = ptr->next;
        free(ptr);
    }
    printf("delete successful!\n");
}
void update(student *start, char *line) //update the past data
{
    int id;
    student *ptr;
    inputstudentid(&id, line);
    if (search(start, &ptr, id) == 0) //search the id is exists or not, and find the ptr
    {
        printf("Update error! studentID not exists!\n");
        return;
    }
    ptr->id = id; //update the data
    inputstudent(ptr, line);
    printf("Update successful!\n");
}
void find(student *ptr, char *pat)
{
    int flag = 0;
    pat[strlen(pat) - 1] = '\0'; //remove '\n'
    while (ptr != NULL)
    {
        if (strstr(ptr->name, pat) != NULL || strstr(ptr->phone, pat) != NULL || strstr(ptr->email, pat) != NULL)
        {
            printf("studentID:%d\tname:%s\tphone:%s\temail:%s\n", ptr->id, ptr->name, ptr->phone, ptr->email);
            flag = 1; //if there are the pat in the ptr, flag = 1
        }
        ptr = ptr->next;
    }
    if (flag == 0)
        printf("Find error! Not exists!\n");
}
void list(student *ptr) //list the all data
{
    while (ptr != NULL)
    {
        printf("studentID:%d\tname:%s\tphone:%s\temail:%s\n", ptr->id, ptr->name, ptr->phone, ptr->email);
        ptr = ptr->next;
    }
}
int main()
{
    student *start = NULL, new;
    char line[150];
    printf("Please input command(i/d/u/f/l/q) and data:\n");
    printf("Insert the record:i studentID\\tname\\tphone\\temail\n");
    printf("Delete the record:d studentID\n");
    printf("Update the record:u studentID\\tname\\tphone\\temail\n");
    printf("Find the record:f [string]\n");
    printf("List the record:l\n");
    printf("Quit:q\n");
    while (fgets(line, 150, stdin) != NULL)
    {
        if (line[0] == 'i')
            insert(&start, &new, line);
        else if (line[0] == 'd')
            delete (&start, line);
        else if (line[0] == 'u')
            update(start, line);
        else if (line[0] == 'f')
            find(start, line + 2);
        else if (line[0] == 'l')
            list(start);
        else if (line[0] == 'q')
            break;
    }
    printf("Thanks for your using!\n");
    return 0;
}