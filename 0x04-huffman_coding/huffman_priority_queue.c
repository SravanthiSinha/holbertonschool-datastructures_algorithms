#include "huffman.h"
#include "heap.h"

/**
 * huffman_priority_queue -  A function that creates a priority queue for the
 * Huffman coding algorithm
 * @data: An array of characters of size `size`
 * @freq: An array containing the associated frequencies (of size `size`)
 * @size: size of the array
 * Return: A pointer to the created min priority_queue_heap (also called
 * priority queue)
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *priority_queue_heap;
	size_t i = 0;
	symbol_t *symbol;
	binary_tree_node_t *node, *nested;

	priority_queue_heap = heap_create(NULL);
	if (priority_queue_heap == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		symbol = symbol_create(data[i], freq[i]);
		if (symbol == NULL)
			return (NULL);
		nested = binary_tree_node(NULL, symbol);
		if (nested == NULL)
			return (NULL);
		node = heap_insert(priority_queue_heap, nested);
		if (node == NULL)
			return (NULL);
	}
	return (priority_queue_heap);
}
