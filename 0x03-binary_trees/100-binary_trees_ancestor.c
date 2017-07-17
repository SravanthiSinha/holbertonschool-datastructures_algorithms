#include "binary_trees.h"

/**
 * binary_trees_ancestor - ffinds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 **/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *node;

	if (!first || !second)
		return (NULL);
	if (!first->parent && !second->parent)
		return (NULL);
	if (!first->parent || second->parent == first)
		return ((binary_tree_t *)first);
	if (!second->parent || first->parent == second)
		return ((binary_tree_t *)second);
	if (first->parent == second->parent)
		return (first->parent);
	if (first->parent != second->parent)
	{
		node = binary_trees_ancestor(first, second->parent);
		return (node != NULL ? node : binary_trees_ancestor(second, first->parent));
	}
	return (NULL);
}
