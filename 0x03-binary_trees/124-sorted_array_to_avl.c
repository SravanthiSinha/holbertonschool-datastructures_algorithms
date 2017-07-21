#include "binary_trees.h"

/**
 * sortedArrayToBST - a function that builds an  BST tree from an sorted array
 * @root: pointer to the root node of the AVL.
 * @arr: a pointer to the first element of the array to be converted
 * @start: the start index for left sub tree
 * @end: the end index for left righ tree
 * Return: a pointer to the root node of the created BST, or NULL on failure
 **/
avl_t *sortedArrayToBST(avl_t *root, int arr[], int start, int end)
{
	avl_t *node = NULL;
	int mid = 0;

	if (start > end)
		return (NULL);

	/* Get the middle element and make it root */
	mid = (start + end) / 2;
	node = binary_tree_node(root, arr[mid]);

	/* Recursively construct the left subtree and make it left child of root */
	node->left = sortedArrayToBST(node, arr, start, mid - 1);
	/* Recursively construct the right subtree and make it right child of root */
	node->right = sortedArrayToBST(node, arr, mid + 1, end);
	return (node);
}

/**
 * sorted_array_to_avl - a function that builds an AVL tree from an array
 * @array:  a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created BST, or NULL on failure
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array)
		return (NULL);
	root = sortedArrayToBST(root, array, 0, size - 1);
	return (root);
}
