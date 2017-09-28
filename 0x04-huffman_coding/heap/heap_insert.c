#include "heap.h"

/**
 * int2bin- Afucntion to convert an integer to a binary string
 * @a: integer to be converted
 * Return: binary string of an integer
 */
char *int2bin(int a)
{
	char *str, *tmp;
	int cnt = 31;

	str = (char *)malloc(33);
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
 * strrev - reverse a string
 * @str: string to be reversed
 * Return: reversed string
 */
char *strrev(char *str)
{
	char *p1, *p2;

	if (!str || !*str)
		return (str);
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return (str);
}

/**
 * get_bottom_node - A function that fetches the bottom node of a tree
 * @heap:  A pointer to the heap where the node has to inserted
 * @data : data to be inserted
 * Return: A pointer to the bottom node
 */
binary_tree_node_t *get_bottom_node(heap_t *heap, void *data)
{
	binary_tree_node_t *temp, *parent, *node;
	int l = 0, r = 0, pos, len, i = 0;
	char *bin = int2bin((int)heap->size + 1);
	char *e = strchr(bin, '1');

	/* get the MSB index*/
	pos = (int)(e - bin);
	bin = bin + pos + 1;
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
	node = binary_tree_node(parent, data);
	if (l > r)
		parent->left = node;
	else
		parent->right = node;
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
	binary_tree_node_t *node = NULL;

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
	node = get_bottom_node(heap, data);
	if (node != NULL)
	{
		heap->size += 1;
		adjust_heap(heap, node);
	}
	return (node);
}
