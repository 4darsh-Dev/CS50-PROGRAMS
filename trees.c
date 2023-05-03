#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>


typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}node;


bool search(node *tree, int number);

int main(void)
{
    printf("Welcome to binary search trees \n");

    // printf("Output : %d\n", search(tree));
}

bool search(node *tree, int number)
{
    if(tree == NULL)
    {
        return false;
    }
    else if(number < tree->number)
    {
        return search(tree->left, number);
    }
    else if(number > tree->number)
    {
        return search(tree->right, number);
    }
    else if(number == tree->number)
    {
        return true;

    }
    return false;
}

