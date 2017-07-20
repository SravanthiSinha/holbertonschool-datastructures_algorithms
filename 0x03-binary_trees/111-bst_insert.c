#include "binary_trees.h"

/**
 * bst_insert -  a function that creates a binary tree node
 * @tree : a double pointer to the root node of the BST to insert the value in
 * @value: the value to store in the node to be inserted
 * Return:  a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = NULL, *prev;
	int r = 0, l = 0;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	else
	{
		node = *tree;
		while (node)
		{
			prev = node;
			r = 0, l = 0;
			if (node->n < value)
			{
				node = node->right;
				r++;
			}
			else if (node->n > value)
			{
				node = node->left;
				l++;
			}
			else
				return (NULL);
		}
		node = binary_tree_node(prev, value);
		if (r > l)
			prev->right = node;
		else
			prev->left = node;
	}
	return (node);
}
