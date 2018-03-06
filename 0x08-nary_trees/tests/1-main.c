#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;

	root = nary_tree_insert(NULL, "/");
	if (!root)
	{
		fprintf(stderr, "Failed to create node\n");
		return (EXIT_FAILURE);
	}

	tmp = nary_tree_insert(root, "tmp");
	nary_tree_insert(tmp, "tmp_file");

	var = nary_tree_insert(root, "var");
	nary_tree_insert(var, "www");

	opt = nary_tree_insert(root, "opt");
	betty = nary_tree_insert(opt, "Betty");
	nary_tree_insert(betty, "betty-style.pl");
	nary_tree_insert(betty, "betty-doc.pl");

	home = nary_tree_insert(root, "home");
	alex = nary_tree_insert(home, "alex");
	nary_tree_insert(alex, "Desktop");
	nary_tree_insert(alex, "Downloads");
	nary_tree_insert(alex, "Pictures");
	nary_tree_insert(alex, "Movies");
	nary_tree_insert(alex, "Documents");
	nary_tree_insert(alex, "Applications");

	nary_tree_delete(root);

	return (EXIT_SUCCESS);
}
