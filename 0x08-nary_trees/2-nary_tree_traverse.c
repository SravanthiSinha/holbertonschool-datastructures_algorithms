#include "nary_trees.h"

/**
 * nary_tree_traverse_helper - A helper function that goes through an N-ary
 * tree node by node.
 * @root: A pointer to the root node of the tree to traverse
 * @action: A pointer to a function to execute for each node being traversed
 * @maxdepth: current depth
 * Return: The biggest depth of the tree pointed to by root.
 */
size_t nary_tree_traverse_helper(nary_tree_t const *root,
				 void (*action)(nary_tree_t const *node, size_t depth), size_t maxdepth)
{
	nary_tree_t const *node;
	nary_tree_t const *list = NULL, *temp = NULL;

	node = root;

	if (node)
	{
		action(node, maxdepth++);
		list = node->children;
		while (list)
		{
			temp = list;
			list = list->next;
			nary_tree_traverse_helper(temp, action, maxdepth);
		}
	}
	return (maxdepth);
}

/**
 * nary_tree_traverse - A function that goes through an N-ary tree, node by
 * node.
 * @root: A pointer to the root node of the tree to traverse
 * @action: A pointer to a function to execute for each node being traversed.
 * Return: The biggest depth of the tree pointed to by root.
 */
size_t nary_tree_traverse(nary_tree_t const *root,
			  void (*action)(nary_tree_t const *node, size_t depth))
{
	size_t maxdepth = 0;

	return (nary_tree_traverse_helper(root, action, maxdepth));
}
