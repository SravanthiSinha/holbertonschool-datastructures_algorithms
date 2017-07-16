#include "binary_trees.h"

/**
 * binary_tree_insert_left -  a function that inserts a node as the left-child
 * of another node
 * @parent : a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *cur;

	if (!parent)
		return (NULL);

	tmp = malloc(sizeof(binary_tree_t));
	if (!tmp)
		return (NULL);
	tmp->n = value;
	tmp->right = NULL;
	tmp->left = NULL;

	if (!parent->left)
	{
		parent->left = tmp;
		tmp->parent = parent;
	}
	else
	{
		cur = parent->left;
		parent->left = tmp;
		tmp->parent = parent;
		tmp->left = cur;
		cur->parent = tmp;
	}
	return (tmp);
}
