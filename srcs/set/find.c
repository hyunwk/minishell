#include "includes/set.h"

int bst_find(t_node* root, char *target) 
{
    printf("root: %s\n", root->value);
    if (root == NULL)
        return (0);
    if (root->value == target)
        return (1);
    else if (root->value > target)
        return bst_find(root->left, target);
    else
        return bst_find(root->right, target);
}