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
* func_at_level - a function that goes through a binary tree using
*  at each level and does func
* @node:  a pointer to the node of the tree to traverse
* @func: a pointer to a function to call for each node.
* @level : the level of the givne node
* Return: void
**/
void func_at_level(const binary_tree_t *node, void (*func)(int), int level)
{
	if (!node || !func)
		return;

	if (level == 0)
		func(node->n);
	else if (level > 0)
	{
		func_at_level(node->left, func, level - 1);
		func_at_level(node->right, func, level - 1);
	}
}

/**
* binary_tree_levelorder - a function that goes through a binary tree using
* level-order traversal
* @tree:  a pointer to the root node of the tree to traverse
* @func: a pointer to a function to call for each node.
* Return: void
**/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int d, i;

	if (!tree || !func)
		return;

	d  = binary_tree_height(tree);
	for (i = 0; i <= d; i++)
	{
		func_at_level(tree, func, i);
	}

}
