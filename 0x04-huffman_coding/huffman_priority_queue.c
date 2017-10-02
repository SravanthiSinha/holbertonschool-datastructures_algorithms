#include "huffman.h"
#include "heap.h"

/**
 * symbol_cmp - Compares two symbols
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two symbols
 */
static int symbol_cmp(void *p1, void *p2)
{
	binary_tree_node_t *n1, *n2;
	int c1, c2;

	n1 = (binary_tree_node_t *) p1;
	n2 = (binary_tree_node_t *) p2;
	c1 = ((symbol_t *) n1->data)->freq;
	c2 = ((symbol_t *) n2->data)->freq;
	return (c1 - c2);
}

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

	priority_queue_heap = heap_create(symbol_cmp);
	if (priority_queue_heap == NULL || data == NULL || freq == NULL || size == 0)
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
