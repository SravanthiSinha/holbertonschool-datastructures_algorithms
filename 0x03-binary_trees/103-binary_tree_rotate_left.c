#include "binary_trees.h"

/* resource: http://cs.lmu.edu/~ray/notes/binarysearchtrees/ */
/**
* binary_tree_rotate_left -  a function that performs a left-rotation
* on a binary tree
* @tree: a pointer to the root node of the tree to rotate
* Return: a pointer to the new root node of the tree once rotated
**/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node, *node2, *node3;

	if (!tree)
		return (NULL);
	if (tree->right)
	{
		node = tree;
		node2 = tree->right;
		if (node->parent && node->parent->n < node->n)
			node->parent->right = node2;
		if (node->parent && node->parent->n > node->n)
			node->parent->left = node2;
		node3 = tree->right->left;
		node2->parent = node->parent;
		node2->left = node;
		node->parent = node2;
		node->right = node3;
		if (node3)
			node3->parent = node;
		tree = node2;
	}
	return (tree);
}
