#include "includes/set.h"

void bst_print(t_node* root)
{
	if(root == NULL)
		return ;
	printf("%s\n", root->value);
	bst_print(root->left);
	bst_print(root->right);
}