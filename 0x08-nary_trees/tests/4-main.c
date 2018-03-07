#include <stdio.h>
#include <stdlib.h>

#include "nary_trees.h"

/**
 * print_node - prints node contents indentented by its depth
 * @node: node to be printed
 * @depth: depth of the node
 */
void print_node(nary_tree_t const *node, size_t depth)
{
	printf("%*s%s\n", (int)depth * 2, "", node->content);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;

	char const *path[] = { "/", "opt", "Betty", "betty-style.pl", NULL };
	char const *path2[] = { "/", "opt", "Betty", "betty-style.pl",
		"Holberton", NULL
	};
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
	if (path_exists(root, (char const *const *)path))
		printf("Path exists!\n");
	else
		printf("Path does not exist\n");
	if (path_exists(root, (char const *const *)path2))
		printf("Path2 exists!\n");
	else
		printf("Path2 does not exist\n");
	nary_tree_delete(root);

	return (EXIT_SUCCESS);
}
