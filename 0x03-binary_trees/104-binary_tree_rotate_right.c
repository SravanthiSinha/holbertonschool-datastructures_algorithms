#include "binary_trees.h"

/* resource: http://cs.lmu.edu/~ray/notes/binarysearchtrees/ */
/**
* binary_tree_rotate_right -  a function that performs a right-rotation
* on a binary tree
* @tree: a pointer to the root node of the tree to rotate
* Return: a pointer to the new root node of the tree once rotated
**/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node, *node2, *node3;

	if (!tree)
		return (NULL);
	if (tree->left)
	{
		node = tree;
		node2 = tree->left;
		if (node->parent && node->parent->n < node->n)
			node->parent->right = node2;
		if (node->parent && node->parent->n > node->n)
			node->parent->left = node2;
		node3 = tree->left->right;
		node2->parent = node->parent;
		node2->right = node;
		node->parent = node2;
		node->left = node3;
		if (node3)
			node3->parent = node;
		tree = node2;
	}
	return (tree);
}
