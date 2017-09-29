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
 * get_bottom_node - A function that deletes the bottom
 * node of a heap and fetches the data of bottom node
 * @heap:  A pointer to the heap where the node has to inserted
 * Return: A pointer to the bottom node
 */
static void *get_bottom_node(heap_t *heap)
{
	void *data;
	binary_tree_node_t *temp, *parent;
	int l = 0, r = 0, pos, len, i = 0;
	char *bin, *bin_str = int2bin((int)heap->size);
	char *e = strchr(bin_str, '1');

	/* get the MSB index */
	pos = (int)(e - bin_str);
	bin = strdup(bin_str + pos + 1);
	temp = heap->root;
	len = strlen(bin);
	while (i < len)
	{
		parent = temp;
		if (bin[i] == '0')
		{
			temp = temp->left;
			l++;
			r = 0;
		} else
		{
			temp = temp->right;
			r++;
			l = 0;
		}
		i++;
	}
	free(bin);
	free(bin_str);
	data = temp->data;
	if (l > r)
		parent->left = NULL;
	else
		parent->right = NULL;
	free(temp);
	heap->size -= 1;
	return (data);
}

/**
 * swap_int - swap intger pointers
 * @a: first no
 * @b: sec no
 */
static void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
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
 */
static void adjust_heap(heap_t *heap)
{
	binary_tree_node_t *temp;

	temp = heap->root;
	while (temp)
	{
		if (temp->data && temp->left && temp->right && temp->left->data
		    && temp->right->data)
		{
			if (heap->data_cmp(temp->left->data, temp->right->data)
			    > 0)
			{
				swap_int(temp->data, temp->right->data);
				temp = temp->right;
			} else
			{
				swap_int(temp->data, temp->left->data);
				temp = temp->left;
			}
		} else if (temp->data && temp->left && ((temp->left->data &&
							 heap->data_cmp(temp->data, temp->left->data) > 0)
							|| temp->left->data == NULL))
		{
			swap(&temp->data, &temp->left->data);
			temp = temp->left;
		} else if (temp->data && temp->right && ((temp->right->data &&
							  heap->data_cmp(temp->data, temp->right->data) > 0)
							 || temp->right->data == NULL))
		{
			swap(&temp->data, &temp->right->data);
			temp = temp->right;
		} else
			return;
	}
}

/**
 * heap_extract- A function that extratcs the root value in a Heap
 * @heap:  A pointer to the heap in which root has to be extracted
 * Return: A pointer to the data that was stored in the root node of the heap
 */
void *heap_extract(heap_t *heap)
{
	void *data = NULL, *last = NULL;

	if (heap == NULL)
		return (NULL);
	if (heap->root == NULL || heap->size == 0 || heap->data_cmp == NULL)
		return (NULL);

	/*GET the element to the bottom level of the heap. */
	last = get_bottom_node(heap);
	data = heap->root->data;
	/*Replace the root of the heap with the last element on the last level. */
	heap->root->data = last;
	adjust_heap(heap);
	return (data);
}
