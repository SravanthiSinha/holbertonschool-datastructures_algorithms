#include "binary_trees.h"

/**
 * binary_tree_delete -  a function that deletes an entire binary tree
 * @tree : a pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		if (tree->left)
			binary_tree_delete(tree->left);
		if (tree->right)
			binary_tree_delete(tree->right);
		free(tree);
	}
}
