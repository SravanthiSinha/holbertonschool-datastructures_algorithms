#include "nary_trees.h"

/**
 * path_exists - checks if a path exists in an N-ary tree.
 * @root: A pointer to the root node of the tree.
 * @path: a NULL terminated array of string.
 * Return: 1 on success, 0 on failure.
 */
int path_exists(nary_tree_t const *root, char const *const *path)
{
	nary_tree_t const *node;
	int i;

	node = root;
	if (root == NULL || path == NULL || path[0] == NULL)
		return (0);
	for (i = 0; path[i] && node; i++)
	{
		while (strcmp(node->content, path[i]) != 0)
		{
			if (node->next == NULL)
				return (0);
			node = node->next;
		}
		node = node->children;
	}
	return (path[i] == NULL);
}
