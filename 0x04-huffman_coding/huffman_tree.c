#include "heap.h"
#include "huffman.h"

/**
 * huffman_tree - A function that builds the Huffman tree
 * @data: An array of characters of size @size
 * @freq: An array containing the associated frequencies (of size @size too)
 * @size: size of an array
 * Return: A pointer to the root node of the Huffman tree, or NULL if it fails
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *priority_queue = NULL;
	binary_tree_node_t *huffman_tree = NULL;
	int ret = 1;

	if (data == NULL || freq == NULL || size == 0)
		return (NULL);
	priority_queue = huffman_priority_queue(data, freq, size);
	if (priority_queue == NULL)
		return (NULL);

	while (priority_queue->size > 1 && ret)
	{
		ret = huffman_extract_and_insert(priority_queue);
	}
	huffman_tree = priority_queue->root->data;
	heap_delete(priority_queue, NULL);
	if (ret)
		return (huffman_tree);
	return (NULL);
}
