#include "heap.h"

void binary_tree_delete(binary_tree_node_t *node, void (*free_data)(void *));

/**
 * binary_tree_delete -  a function that deletes an entire binary tree
 * @node : a pointer to the root node of the tree to delete
 * @free_data: A pointer to a function that will be used to
 * free the content of a node
 */
void binary_tree_delete(binary_tree_node_t *node, void (*free_data)(void *))
{
	if (node)
	{
		if (node->left)
			binary_tree_delete(node->left, free_data);
		if (node->right)
			binary_tree_delete(node->right, free_data);
		if (free_data != NULL)
			free_data(node->data);
		free(node);
	}
}

/**
 * heap_delete - A function that deallocates a heap
 * @heap: A pointer to the heap to delete
 * @free_data: A pointer to a function that will be used to
 * free the content of a node
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (heap == NULL)
		return;
	binary_tree_delete(heap->root, free_data);
	heap->size = 0;
	free(heap);
}
