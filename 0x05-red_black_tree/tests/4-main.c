#include "rb_trees.h"
#include <stdio.h>
#include <stdlib.h>

void rb_tree_print(const rb_tree_t *tree);

/**
 * main - Entry point
 *
 * Return: 0 on success
 */
int main(void)
{
	rb_tree_t *tree;

	int array[] = { 20, 30, 25, 89, 10, 35, 250, 8, 7 };
	size_t n = sizeof(array) / sizeof(array[0]);

	tree = array_to_rb_tree(array, n);
	if (!tree)
		return (1);

	rb_tree_print(tree);

	tree = rb_tree_remove(tree, 10);
	printf("\nDeleted: %d\n", 10);

	rb_tree_print(tree);

	tree = rb_tree_remove(tree, 25);
	printf("\nDeleted: %d\n", 25);
	rb_tree_print(tree);
	printf("Red-Black Tree is %s\n",
	       rb_tree_is_valid(tree) ? "valid" : "Invalid");
	tree = rb_tree_remove(tree, 20);
	printf("\nDeleted: %d\n", 20);
	rb_tree_print(tree);
	printf("Red-Black Tree is %s\n",
	       rb_tree_is_valid(tree) ? "valid" : "Invalid");
	tree = rb_tree_remove(tree, 250);
	printf("\nDeleted: %d\n", 250);
	rb_tree_print(tree);
	printf("Red-Black Tree is %s\n",
	       rb_tree_is_valid(tree) ? "valid" : "Invalid");
	tree = rb_tree_remove(tree, 89);
	printf("\nDeleted: %d\n", 89);
	rb_tree_print(tree);
	printf("Red-Black Tree is %s\n",
	       rb_tree_is_valid(tree) ? "valid" : "Invalid");
	return (0);
}
