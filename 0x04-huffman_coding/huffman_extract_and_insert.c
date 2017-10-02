#include "heap.h"
#include "huffman.h"
/**
 * huffman_extract_and_insert- A function that extracts the two nodes of
 * the priority queue and insert a new one
 * @priority_queue: A pointer to the priority queue to extract from
 * Return: 1 on success or 0 on failure
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *first_node = NULL, *second_node = NULL;
	size_t freq = 0;
	symbol_t *symbol;
	binary_tree_node_t *node, *nested;

	if (priority_queue == NULL)
		return (1);

	first_node = (binary_tree_node_t *) heap_extract(priority_queue);
	if (priority_queue->size > 0)
		second_node =
		    (binary_tree_node_t *) heap_extract(priority_queue);
	if (first_node == NULL || second_node == NULL)
		return (0);
	freq = ((symbol_t *) first_node->data)->freq +
	    ((symbol_t *) second_node->data)->freq;

	symbol = symbol_create(-1, freq);
	if (symbol == NULL)
		return (0);
	nested = binary_tree_node(NULL, symbol);
	if (nested == NULL)
		return (0);
	if (first_node)
	{
		nested->left = first_node;
		first_node->parent = nested;
	}
	if (second_node)
	{
		nested->right = second_node;
		second_node->parent = nested;
	}
	node = heap_insert(priority_queue, nested);
	if (node == NULL)
		return (0);
	return (1);
}
