#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data
{
    int count;
    char word[1002];
    struct data *right;
    struct data *left;
} Data;
Data *search(Data *root, char *word)
{
    while (root != NULL)
    {
        if (strcmp(word, root->word) == 0)
            return root;
        else if (strcmp(word, root->word) < 0)
            root = root->left;
        else if (strcmp(word, root->word) > 0)
            root = root->right;
    }
    return root;
}
Data *insert(Data *root, char *line)
{
    Data *ptr = root, *new;
    line = strstr(line, "\t") + 1;
    line[strlen(line) - 1] = '\0';
    if (root == NULL)
    {
        new = malloc(sizeof(Data));
        new->count = 1;
        strcpy(new->word, line);
        new->right = NULL;
        new->left = NULL;
        return new;
    }
    while (ptr != NULL)
    {
        if (strcmp(line, ptr->word) < 0 && ptr->left != NULL)
            ptr = ptr->left;
        else if (strcmp(line, ptr->word) > 0 && ptr->right != NULL)
            ptr = ptr->right;
        else if (strcmp(line, ptr->word) == 0)
        {
            ptr->count++;
            break;
        }
        else
        {
            new = malloc(sizeof(Data));
            new->count = 1;
            strcpy(new->word, line);
            new->right = NULL;
            new->left = NULL;
            if (strcmp(new->word, ptr->word) < 0)
                ptr->left = new;
            else
                ptr->right = new;
            break;
        }
    }
    return root;
}
void delete (Data *root, char *line)
{
    Data *ptr;
    line = strstr(line, "\t") + 1;
    line[strlen(line) - 1] = '\0';
    ptr = search(root, line);
    ptr->count--;
    if (ptr->count < 0)
        ptr->count = 0;
}
void query(Data *root, char *line)
{
    Data *ptr;
    line = strstr(line, "\t") + 1;
    line[strlen(line) - 1] = '\0';
    ptr = search(root, line);
    if (ptr->count > 0)
        printf("%s\t%d\n", ptr->word, ptr->count);
}
void inorder(Data *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    if (root->count > 0)
        printf("%s\t%d\n", root->word, root->count);
    inorder(root->right);
}
int main()
{
    Data *root = NULL;
    char line[1002];
    while (fgets(line, 1002, stdin) != NULL)
    {
        if (strstr(line, "insert") != NULL)
            root = insert(root, line);
        else if (strstr(line, "delete") != NULL)
            delete (root, line);
        else if (strstr(line, "query") != NULL)
        {
            printf("----------\n");
            query(root, line);
            printf("----------\n");
        }
        else if (strstr(line, "inorder") != NULL)
        {
            printf("----------\n");
            inorder(root);
            printf("----------\n");
        }
    }
}