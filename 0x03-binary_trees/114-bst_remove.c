#include "binary_trees.h"

/**
 * minValueNode -  a function that removes a node from a Binary Search Tree
 * @node : a pointer to the root node of the tree to remove a node of
 * Return: a pointer to the left most node
 */
bst_t *minValueNode(bst_t *node)
{
	bst_t *current = node;

	while (current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove -  a function that removes a node from a Binary Search Tree
 * @root : a pointer to the root node of the tree to remove a node of
 * @value: the value to look for
 * Return: a pointer to the new root node of the tree after removing the
 * desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *min_node, *temp = NULL;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (temp);
		}
		else if (root->left == NULL)
		{
			temp = root->right;
			if (root->parent)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			if (root->parent)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		min_node = minValueNode(root->right);
		root->n = min_node->n;
		root->right = bst_remove(root->right, min_node->n);
	}
	return (root);
}
