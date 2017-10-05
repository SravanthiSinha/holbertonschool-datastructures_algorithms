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
 * @exit_status: set to EXIT_FAILURE if strdup fails
 * Return: A pointer to the bottom node
 */
static void *get_bottom_node(heap_t *heap, int *exit_status)
{
	binary_tree_node_t *temp = NULL, *parent = NULL;
	int l = 0, r = 0, pos, len, i = 0;
	char *bin = NULL, *b_str = int2bin((int)heap->size), *e =
	    strchr(b_str, '1');

	pos = (int)(e - b_str);	/* get the MSB index */
	bin = strdup(b_str + pos + 1);
	if (bin == NULL)
		*exit_status = EXIT_FAILURE;
	else
	{
		temp = heap->root;
		parent = temp;
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
		if (l > r)
			parent->left = NULL;
		else
			parent->right = NULL;
	}
	free(b_str);
	return (temp);
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
			if ((heap->data_cmp(temp->data, temp->right->data) >= 0)
			    && (heap->
				data_cmp(temp->right->data,
					 temp->left->data) < 0))
			{
				swap(&temp->data, &temp->right->data);
				temp = temp->right;
			} else if (heap->
				   data_cmp(temp->data, temp->left->data) >= 0)
			{
				swap(&temp->data, &temp->left->data);
				temp = temp->left;
			} else
				return;
		} else if (temp->data && temp->left &&
			   ((temp->left->data &&
			     heap->data_cmp(temp->data, temp->left->data) >= 0)
			    || temp->left->data == NULL))
		{
			swap(&temp->data, &temp->left->data);
			temp = temp->left;
		} else if (temp->data && temp->right &&
			   ((temp->right->data &&
			     heap->data_cmp(temp->data, temp->right->data) >= 0)
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
	void *data = NULL;
	binary_tree_node_t *last = NULL, *extract_node = NULL;
	int exit_status = EXIT_SUCCESS;

	if (heap == NULL)
		return (NULL);
	if (heap->root == NULL)
		return (NULL);

	extract_node = heap->root;
	if (heap->root->left == NULL && heap->root->right == NULL)
	{
		data = extract_node->data;
		free(heap->root);
		heap->root = NULL;
		heap->size--;
		return (data);
	}
	last = get_bottom_node(heap, &exit_status);
	if (exit_status == EXIT_SUCCESS)
	{
		data = extract_node->data;
		/*Replace the root of the heap with the last element on the last level. */
		if (last)
			swap(&heap->root->data, &last->data);
		free(last);
		last = NULL;
		heap->size--;
		if (heap->data_cmp != NULL && heap->size > 1)
			adjust_heap(heap);
	}
	return (data);
}
