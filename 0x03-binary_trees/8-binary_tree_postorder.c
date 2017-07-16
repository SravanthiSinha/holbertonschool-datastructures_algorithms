#include "binary_trees.h"

/**
 * binary_tree_postorder -  a function that goes through a binary tree using
 * postorder traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!func)
		return;
	if (tree)
	{
		if (tree->left)
			binary_tree_postorder(tree->left, func);
		if (tree->right)
			binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
