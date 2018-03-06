#include "nary_trees.h"

/**
 * nary_tree_insert -  insert a node in a N-ary tree.
 * @parent: A pointer to the parent node.
 * @str: The string to be stored in the created node.
 * Return: a pointer to the created node, or NULL on failure.
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *node;

	node = malloc(sizeof(nary_tree_t));

	if (node == NULL)
		return (NULL);
	node->content = strdup(str);
	node->parent = parent;
	node->children = NULL;
	node->nb_children = 0;
	node->next = NULL;
	if (parent != NULL)
	{
		/*The created node must be added at the beginning */
		/*of the parent’s children linked list. */
		node->next = parent->children;
		parent->children = node;
		parent->nb_children++;
	}
	return (node);
}
