#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

int bstSearch(struct Node *root, int key, int *count)
{
    *count = 0;

    while (root != NULL)
    {
        (*count)++;

        if (root->data == key)
            return 1;

        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

int linearSearch(int a[], int n, int key, int *count)
{
    int i;

    *count = 0;

    for (i = 0; i < n; i++)
    {
        (*count)++;

        if (a[i] == key)
            return 1;
    }

    return 0;
}

int main()
{
    struct Node *root = NULL;

    int a[] = {45, 20, 60, 10, 30, 50, 70, 25, 55};
    int keys[] = {25, 55, 90};

    int n = 9;
    int i;
    int bstCount, linearCount;

    for (i = 0; i < n; i++)
        root = insert(root, a[i]);

    printf("Key\tBST Search\tLinear Search\n");

    for (i = 0; i < 3; i++)
    {
        bstSearch(root, keys[i], &bstCount);
        linearSearch(a, n, keys[i], &linearCount);

        printf("%d\t%d comparisons\t%d comparisons\n",
               keys[i], bstCount, linearCount);
    }

    return 0;
}