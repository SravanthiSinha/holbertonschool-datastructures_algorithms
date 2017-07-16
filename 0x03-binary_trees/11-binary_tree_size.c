#include "binary_trees.h"

/**
* binary_tree_size - measures the size of a binary tree
* @tree: pointer to the root node of the tree to measure the size of
* Return: depth or 0 if root or its children is NULL
**/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree)
	{
		if (tree->left)
			size += binary_tree_size(tree->left);
		if (tree->right)
			size += binary_tree_size(tree->right);
		return (size);
	}
	return (0);
}
