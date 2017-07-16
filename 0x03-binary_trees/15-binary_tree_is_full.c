#include "binary_trees.h"


/**
 * binary_tree_is_full -  a function  thatchecks if a binary tree is full
 * @node : a pointer to the node to check
 * Return: 1 if node is a root, and 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *node)
{
	if (node)
	{
		if ((node->left && !node->right) || (!node->left && node->right))
			return (0);
		else if (node->left && node->right)
			return (binary_tree_is_full(node->left) &&
				binary_tree_is_full(node->right));
		return (1);
	}
	return (0);
}
