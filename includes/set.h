#ifndef SET_H
# define SET_H
/*macro*/

/*struct*/
typedef struct s_node
{
	char			*value;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;
/*include*/
#include <stdlib.h>
#include <stdio.h>
/*prototype*/
int		bst_find(t_node* root, char *target);
t_node	*bst_insert(t_node *root, char *value);
void	bst_print(t_node* root);

#endif