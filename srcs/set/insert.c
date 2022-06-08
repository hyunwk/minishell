#include "includes/set.h"

t_node*	make_node(char *value)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->value = value;
	return (node);
}

/*
루트 노드에서부터 탐색하며 삽입하는 노드의 값이 현재 노드 보다 더 크면 오른쪽 자식을 방문,
작으면 왼쪽 자식을 방문하는 것을 반복하다가 NULL을 만나면 해당 위치에 노드를 삽입하고 종료한다.
*/
//envp 저장할때만 쓰니까 insert할 때마다 root 갱신하기
t_node	*bst_insert(t_node *root, char *value)
{
	if (root == NULL)
	{
		root = make_node(value);
		if (root == NULL)
			return (NULL);
	}
	else
	{
		if (root->value > value)
			root->left = bst_insert(root->left, value);
		else
			root->right = bst_insert(root->right, value);
	}
	return (root);
}