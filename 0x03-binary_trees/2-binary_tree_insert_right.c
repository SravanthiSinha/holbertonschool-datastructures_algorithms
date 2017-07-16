#include "binary_trees.h"

/**
 * binary_tree_insert_right -  a function that inserts a node as the
 * right-child of another node
 * @parent : a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *cur;

	if (!parent)
		return (NULL);

	tmp = malloc(sizeof(binary_tree_t));
	if (!tmp)
		return (NULL);
	tmp->n = value;
	tmp->left = NULL;
	tmp->right = NULL;

	if (!parent->right)
	{
		parent->right = tmp;
		tmp->parent = parent;
	}
	else
	{
		cur = parent->right;
		parent->right = tmp;
		tmp->parent = parent;
		tmp->right = cur;
		cur->parent = tmp;
	}
	return (tmp);
}
