#include "binary_trees.h"

/**
 * binary_tree_is_root -  a function that checks if a given node is a root
 * @node : a pointer to the node to check
 * Return: 1 if node is a root, and 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || (node && node->parent))
		return (0);
	return (1);
}
