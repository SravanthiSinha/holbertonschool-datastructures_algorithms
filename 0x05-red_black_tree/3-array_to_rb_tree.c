#include "rb_trees.h"

/**
* array_to_rb_tree - a function that builds a Red-Black Tree from an array
* @array:  a pointer to the first element of the array to be converted
* @size: the number of element in the array
* Return: a pointer to the root node of the created RBT, or NULL on failure
**/
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	rb_tree_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);
	for (i = 0; i < size; i++)
		rb_tree_insert(&root, array[i]);
	return (root);
}
