#include "binary_trees.h"

/**
 * binary_tree_node -  a function that creates a binary tree node
 * @parent : a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *temp, *node;

	temp = malloc(sizeof(binary_tree_t));
	if (!temp)
		return (NULL);
	temp->n = value;
	temp->left = NULL;
	temp->right = NULL;
	if (parent == NULL)
	{
		temp->parent = NULL;
		parent = temp;
	}
	else
	{
		node = parent;
		if (node->n < value)
			node->right = temp;
		else
			node->left = temp;
		temp->parent = node;
	}
	return (temp);
}
