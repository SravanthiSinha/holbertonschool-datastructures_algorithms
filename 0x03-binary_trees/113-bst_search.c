#include "binary_trees.h"

/**
 * bst_search -  a function that searches for a value in a Binary Search Tree
 * @tree : a pointer to the root node of the BST to search
 * @value: the value to look for
 * Return: a pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = NULL;

	if (tree)
	{
		node = (bst_t *)tree;
		while (node)
		{
			if (node->n < value)
				node = node->right;
			else if (node->n > value)
				node = node->left;
			else
				return (node);
		}
	}
	return (node);
}
