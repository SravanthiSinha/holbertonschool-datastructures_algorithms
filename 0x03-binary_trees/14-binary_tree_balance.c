#include "binary_trees.h"

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
 * binary_tree_balance -  a function  that measures the balance factor
 * of a binary tree
 * @node : a pointer to the node to check
 * Return: 1 if node is a root, and 0 otherwise
 */
int binary_tree_balance(const binary_tree_t *node)
{
	int left_height = 0, right_height = 0;

	if (node)
	{
		if (node->left)
		{
			left_height = binary_tree_height(node->left) + 1;
		}
		if (node->right)
		{
			right_height = binary_tree_height(node->right) + 1;
		}
	}
	return (left_height - right_height);
}
