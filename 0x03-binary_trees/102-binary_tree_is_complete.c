#include "binary_trees.h"

/*
* implemented  theory from
*http://www.techiedelight.com/check-given-binary-tree-complete-binary-tree-not/
*/

/**
* no_nodes - calculates n of a given tree
* @tree: pointer to root of tree
* Return: n of tree
**/
size_t no_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + no_nodes(tree->left) + no_nodes(tree->right));
}

/**
* check_node_index - checks the node at a given index
* @n: total number of nodes in the tree
* @index: current node index
* @tree: pointer to root node
* Return: 0 if the index of a given node is equal or greater than the
* n or 1 if its null
**/
int check_node_index(size_t n, size_t index, const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (index >= n)
		return (0);
	return (check_node_index(n, 2 * index + 1, tree->left) &&
		check_node_index(n, 2 * index + 2, tree->right));
}
/**
* binary_tree_is_complete - checks if a binary tree is complete
* @tree: pointer to root of tree
* Return: 1 if tree is complete or 0 if not or NULL
**/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (check_node_index(no_nodes(tree), 0, tree));
}
