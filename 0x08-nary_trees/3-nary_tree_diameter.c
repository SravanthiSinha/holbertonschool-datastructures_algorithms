#include "nary_trees.h"

/**
 * nary_tree_depth - computes the depth of an N-ary tree
 * @root: A pointer to the root node of the tree to compute the diameter of.
 * Return: The depth of the tree pointed to by root.
 */
size_t nary_tree_depth(nary_tree_t const *root)
{
	size_t maxdepth = 0;
	nary_tree_t const *list = NULL;

	if (root == NULL)
		return (0);

	list = root->children;
	/* Check for all children and find the maximum depth */
	while (list)
	{
		maxdepth = MAXIMUM(maxdepth, nary_tree_depth(list));
		list = list->next;
	}
	return (1 + maxdepth);
}

/**
 * nary_tree_diameter - computes the diameter of an N-ary tree
 * @root: A pointer to the root node of the tree to compute the diameter of.
 * Return: The diameter of the tree pointed to by root.
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t diameter = 0;
	size_t max1 = 0, max2 = 0, h = 0;
	nary_tree_t const *list = NULL;

	if (root == NULL)
		return (0);
/*Find top two highest children*/
	list = root->children;
/* Check for all children and find the maximum depth */
	while (list)
	{
		h = nary_tree_depth(list);
		if (h > max1)
			max2 = max1, max1 = h;
		else if (h > max2)
			max2 = h;
		list = list->next;
	}
	/*Iterate over each child for diameter */
	/*Find top two highest children */
	list = root->children;
	/* Check for all children and find the maximum depth */
	while (list)
	{
		diameter = MAXIMUM(diameter, nary_tree_diameter(list));
		list = list->next;
	}
	return (MAXIMUM(diameter, max1 + max2 + 1));
}
