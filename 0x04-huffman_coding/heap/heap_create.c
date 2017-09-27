#include "heap.h"

/**
 * heap_create- A function that creates a Heap data structure
 * @data_cmp: A pointer to a comparison function
 * Return:  A pointer to the created heap_t structure, or NULL if it fails
 */
heap_t *heap_create(int (*data_cmp) (void *, void *))
{
	heap_t *heap = NULL;

	heap = malloc(sizeof(heap_t));

	if (heap == NULL)
		return (NULL);

	heap->root = NULL;
	heap->size = 0;
	heap->data_cmp = data_cmp;
	return (heap);
}
