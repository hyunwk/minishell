#include <stdio.h>
#include "includes/minishell.h"

void	init_envp(char *envp[])
{
	int		i;
	t_node	*tree;

	i = 0;
	tree = NULL;
	while (envp[i])
	{
		tree = bst_insert(tree, envp[i]);
		++i;
	}
	//bst_print(tree);
	printf("%d\n", bst_find(tree, "SHLVL=1"));
	//node free하는 코드 
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	init_envp(envp);
	/*while (1)
		minishell();*/
	return (0);
}