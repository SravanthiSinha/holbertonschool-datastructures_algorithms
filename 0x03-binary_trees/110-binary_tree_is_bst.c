#include "binary_trees.h"


/**
* isBST - helper function
* @tree: pointer to root of tree
* @min: min value
* @max: max value
* Return: 1 if tree is bst or NULL or 0 if not
**/
int isBST(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (isBST(tree->left, min, tree->n) && isBST(tree->right, tree->n, max));
}


/**
* binary_tree_is_bst - checks if a binary tree is bst
* @tree: pointer to root of tree
* Return: 1 if tree is complete or 0 if not or NULL
**/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (isBST(tree, INT_MIN, INT_MAX));
}
