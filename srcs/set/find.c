#include "includes/set.h"
#include <string.h>

int bst_find(t_node* root, char *target) 
{
    if (root == NULL)
        return (0);
    if (strcmp(root->value, target))
        return (1);
    else if (root->value > target)
        return bst_find(root->left, target);
    else
        return bst_find(root->right, target);
}