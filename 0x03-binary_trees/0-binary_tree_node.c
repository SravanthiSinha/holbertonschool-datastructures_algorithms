#include "binary_trees.h"

/**
* binary_tree_node - creates a binary tree node
* @parent: pointer to root of tree
* @value: value of the node
* Return: pointer to new node or NULL
**/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	temp = malloc(sizeof(binary_tree_t));
	if (!temp)
		return (NULL);
	temp->n = value;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = parent;
	return (temp);
}
