#include "nary_trees.h"

/**
 * nary_tree_delete - Deallocates an entire N-ary tree.
 * @tree: N-ary tree to be deallocated.
 */
void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *node;
	nary_tree_t *list = NULL, *temp = NULL;

	node = tree;

	if (node)
	{
		list = node->children;
		while (list)
		{
			temp = list;
			list = list->next;
			nary_tree_delete(temp);
		}
		free(node->content);
		free(node);
	}
}
