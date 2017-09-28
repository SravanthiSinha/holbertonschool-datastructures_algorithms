#include "heap.h"

/**
 * get_bottom_parent - A function that fetches the bottom node of a tree
 * @node:  A pointer to the current node
 * @dir : left or right
 * Return: A pointer to the bottom node
 */
binary_tree_node_t *get_bottom_parent(binary_tree_node_t *node, int *dir)
{
	if (node != NULL)
	{
		if (!node->left && !node->right)
			return (node);
		if (node->left && !node->right)
		{
			*dir = right;
			return (node);
		}
		if (node->left)
		{
			*dir = left;
			return (get_bottom_parent(node->left, dir));
		} else if (node->right)
		{
			*dir = right;
			return (get_bottom_parent(node->right, dir));
		}
	}
	return (node);
}

/**
 * swap - swap intger pointers
 * @a: first no
 * @b: sec no
 */
void swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * adjust_heap- A function to compare and set the order
 * @heap: A pointer to the heap to be ordered
 * @node: newly added node
 */
void adjust_heap(heap_t *heap, binary_tree_node_t *node)
{
	binary_tree_node_t *temp;

	temp = node;
	while (temp->parent
	       && heap->data_cmp(temp->data, temp->parent->data) < 0)
	{
		swap(temp->data, temp->parent->data);
		temp = temp->parent;
	}
}

/**
 * heap_insert- A function that inserts a value in a Min Binary Heap
 * @heap:  A pointer to the heap in which the node has to be inserted
 * @data: A pointer containing the data to store in the new node
 * Return: A pointer to the created node containing data, or NULL if it fails
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *bottom_parent = NULL, *node = NULL;
	int dir = left;

	if (heap == NULL || data == NULL)
		return (NULL);
	if (heap->root == NULL)
	{
		heap->root = binary_tree_node(NULL, data);
		if (heap->root != NULL)
			heap->size += 1;
		return (heap->root);
	}
	/*Add the element to the bottom level of the heap. */
	bottom_parent = get_bottom_parent(heap->root, &dir);
	node = binary_tree_node(bottom_parent, data);
	if (dir == left)
		bottom_parent->left = node;
	else
		bottom_parent->right = node;
	if (node != NULL)
	{
		heap->size += 1;
		adjust_heap(heap, node);
	}
	return (node);
}
