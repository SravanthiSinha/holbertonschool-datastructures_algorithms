#include "heap.h"

/**
 * int2bin- Afucntion to convert an integer to a binary string
 * @a: integer to be converted
 * Return: binary string of an integer
 */
static char *int2bin(int a)
{
	char *str, *tmp;
	int cnt = 31;

	str = (char *)calloc(1, 33);
	tmp = str;
	while (cnt > -1)
	{
		str[cnt] = '0';
		cnt--;
	}
	cnt = 31;
	while (a > 0)
	{
		if (a % 2 == 1)
		{
			str[cnt] = '1';
		}
		cnt--;
		a = a / 2;
	}
	return (tmp);

}

/**
 * get_bottom_node - A function that creates and returns the bottom
 * node of a heap
 * @heap:  A pointer to the heap where the node has to inserted
 * @data : data to be inserted
 * Return: A pointer to the bottom node
 */
static binary_tree_node_t *get_bottom_node(heap_t *heap, void *data)
{
	binary_tree_node_t *temp, *parent, *node;
	int l = 0, r = 0, pos, len, i = 0;
	char *bin = NULL, *bin_str = int2bin((int)heap->size + 1);
	char *e = strchr(bin_str, '1');

	/* get the MSB index */
	pos = (int)(e - bin_str);
	bin = strdup(bin_str + pos + 1);
	temp = heap->root;
	parent = heap->root;
	len = strlen(bin);
	while (i < len)
	{
		parent = temp;
		if (bin[i] == '0')
		{
			temp = temp->left;
			r = 0;
			l++;
		} else
		{
			temp = temp->right;
			l = 0;
			r++;
		}
		i++;
	}
	free(bin);
	free(bin_str);
	node = binary_tree_node(parent, data);
	if (l > r)
		parent->left = node;
	else
		parent->right = node;
	return (node);

}

/**
 * swap - swap  pointers
 * @a: first
 * @b: sec
 */
static void swap(void **a, void **b)
{
	void *c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * adjust_heap- A function to compare and set the order
 * @heap: A pointer to the heap to be ordered
 * @node: newly added node
 */
static void adjust_heap(heap_t *heap, binary_tree_node_t *node)
{
	binary_tree_node_t *temp;

	temp = node;
	while (temp->parent)
	{
		if (temp->data == NULL)
			swap(&temp->data, &temp->parent->data);
		else if (temp->parent->data && heap->data_cmp(temp->data,
							      temp->parent->
							      data) < 0)
			swap(&temp->data, &temp->parent->data);
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
	binary_tree_node_t *node = NULL;

	if (heap == NULL)
		return (NULL);
	if (heap->root == NULL)
	{
		heap->root = binary_tree_node(NULL, data);
		if (heap->root != NULL)
			heap->size += 1;
		return (heap->root);
	}
	/*Add the element to the bottom level of the heap. */
	node = get_bottom_node(heap, data);
	if (node != NULL)
	{
		heap->size += 1;
		if (heap->data_cmp != NULL)
			adjust_heap(heap, node);
	}
	return (node);
}
