#include "binary_trees.h"

/**
 * binary_tree_depth - measures the  depth of a node in a binary tree
 * @tree: pointer to the root node of the tree to measure the depth of
 * Return: depth or 0 if root or its children is NULL
 **/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);
	if (!tree->parent)
		return (0);
	depth = binary_tree_depth(tree->parent);
	return (depth + 1);
}

/**
 * binary_trees_ancestor - ffinds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 **/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	int depth_f, depth_s;
	binary_tree_t *s, *f;

	f = (binary_tree_t *)first;
	s = (binary_tree_t *)second;
	if (!first || !second)
		return (NULL);
	depth_f = binary_tree_depth(first);
	depth_s = binary_tree_depth(second);
	printf("%d %d\n", depth_f, depth_s);
	if (depth_f == 0 && depth_s == 0)
		return (NULL);
	if (depth_f > depth_s)
	{
		while (depth_f != depth_s)
		{
			f = f->parent;
			depth_f--;
		}
	}
	if (depth_s > depth_f)
	{
		while (depth_s != depth_f)
		{
			s = s->parent;
			depth_s--;
		}
	}
	if (depth_f == depth_s)
	{
		while ((f->parent && s->parent) && (f->parent != s->parent))
		{
			f = f->parent;
			s = s->parent;
		}
		return (f->parent ? f->parent : s);
	}
	return (NULL);
}
