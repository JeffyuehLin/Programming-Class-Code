#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct bstree
{
    int count;
    char word[20];
    struct bstree *right;
    struct bstree *left;
} bst;
bst *insert(bst *root, char *line, int *total) //the same node count++ or insert the new node
{
    bst *new, *node;
    line += 7;
    line[strlen(line) - 1] = '\0';
    if (root == NULL) //when there isn't any node
    {
        root = malloc(sizeof(bst));
        root->count = 1;
        strcpy(root->word, line);
        root->left = NULL;
        root->right = NULL;
        (*total)++;
        return root;
    }
    node = root;
    while (root != NULL)
    {
        if (strcmp(root->word, line) == 0)
        {
            root->count++;
            break;
        }
        else if (strcmp(line, root->word) < 0 && root->left != NULL)
            root = root->left;
        else if (strcmp(line, root->word) > 0 && root->right != NULL)
            root = root->right;
        else
        {
            new = malloc(sizeof(bst));
            new->count = 1;
            strcpy(new->word, line);
            new->left = NULL;
            new->right = NULL;
            (*total)++;
            if (strcmp(line, root->word) < 0)
                root->left = new;
            else
                root->right = new;
            break;
        }
    }
    return node;
}
void inorder(bst *root) //inorder traversal
{
    if (root == NULL)
        return;
    inorder(root->left);
    if (root->count > 0)
        printf("%s\t%d\n", root->word, root->count);
    inorder(root->right);
}
bst *search(bst *root, char *line) //search the same node
{
    while (root != NULL)
    {
        if (strcmp(root->word, line) == 0)
            return root;
        else if (strcmp(line, root->word) < 0)
            root = root->left;
        else if (strcmp(line, root->word) > 0)
            root = root->right;
    }
    return root;
}
void delete (bst *root, char *line) //delete the smae node by count--
{
    line += 7;
    line[strlen(line) - 1] = '\0';
    root = search(root, line);
    if (root == NULL)
        return;
    root->count--;
    if (root->count < 0)
        root->count = 0;
}
void query(bst *root, char *line) //search the same node and print
{
    line += 6;
    line[strlen(line) - 1] = '\0';
    root = search(root, line);
    if (root != NULL && root->count > 0)
        printf("%s\t%d\n", root->word, root->count);
}
void inputarray(bst *root, bst **s, int total, int *i) //put the node pointer into the array
{
    if (root == NULL)
        return;
    inputarray(root->left, s, total, i);
    s[*i] = root;
    (*i)++;
    inputarray(root->right, s, total, i);
}
void count(bst *root, int total) //list by the count
{
    bst *s[total], *tmp;
    int i = 0, j;
    inputarray(root, s, total, &i);
    for (i = 0; i < total - 1; i++)
        for (j = 0; j < total - 1 - i; j++)
            if (s[j]->count < s[j + 1]->count)
            {
                tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
    for (i = 0; i < total && s[i]->count > 0; i++)
        printf("%d\t%s\n", s[i]->count, s[i]->word);
}
int main()
{
    char line[100];
    int total = 0;
    bst *root = NULL;
    while (fgets(line, 100, stdin) != NULL)
    {
        if (strstr(line, "insert") != NULL)
            root = insert(root, line, &total);
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
        else if (strstr(line, "count") != NULL)
        {
            printf("----------\n");
            count(root, total);
            printf("----------\n");
        }
    }
    return 0;
}