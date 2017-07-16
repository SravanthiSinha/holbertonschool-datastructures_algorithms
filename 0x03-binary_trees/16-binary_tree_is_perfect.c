#include "binary_trees.h"

/**
* binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
* @tree: pointer to the root node of the tree to count the nodes in
* Return: nothing
**/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}

/**
* power - calculates the power of base
* @base: base to be used
* @exponent: power of base
* Return: base^n
**/
int power(int base, size_t exponent)
{
	int result = 1;

	if (exponent == 0)
		return (result);
	while (exponent > 0)
	{
		result *= base;
		exponent -= 1;
	}
	return (result);
}
/**
* binary_tree_height - measures the height of a binary tree
* @tree: pointer to the root node of the tree to measure the height of
* Return: height or 0 if root or its children is NULL
**/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * binary_tree_is_perfect -  a function  thatchecks if a binary tree is perfect
 *(ie) number of nodes = 2^(n+1)-1 with n being the height of the tree
 * @tree : a pointer to the node to check
 * Return: 1 if node is a root, and 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int h = 0, n = 0;

	if (tree)
	{
		n = binary_tree_nodes(tree);
		h = binary_tree_height(tree);
		if (n == (power(2, h + 1) - 1))
			return (1);
	}
	return (0);
}
