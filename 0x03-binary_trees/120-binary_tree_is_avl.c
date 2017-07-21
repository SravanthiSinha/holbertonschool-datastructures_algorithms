#include "binary_trees.h"

/**
* height - measures the height of a binary tree
* @tree: pointer to the root node of the tree to measure the height of
* Return: height or 0 if root or its children is NULL
**/
size_t height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	left = height(tree->left);
	right = height(tree->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}


/**
* is_balanced - checks if a given bst is balanced or not
* @tree: pointer to the root node of the tree to check
* Return: 1 if AVL, 0 otherwise
**/
int is_balanced(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (abs(height(tree->left) - height(tree->right)) > 1)
		return (0);
	return (is_balanced(tree->left) && is_balanced(tree->right));
}



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
	return (isBST(tree->left, min, tree->n - 1) &&
		isBST(tree->right, tree->n + 1, max));
}

/*
* Properties of an AVL Tree:
* An AVL Tree is a BST
* And the balance factor of each and every node must be -1, 0 or 1
*/
/**
* binary_tree_is_avl - checks if a binary tree is AVL
* @tree: pointer to root of tree
* Return: 1 if tree is complete or 0 if not or NULL
**/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree && isBST(tree, INT_MIN, INT_MAX) && is_balanced(tree))
		return (1);
	return (0);
}
