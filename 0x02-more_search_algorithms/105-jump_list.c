#include "search_algos.h"

/**
 * jump_list -  A function that searches for a value in a sorted array of
 * integers using the Jump search algorithm
 * @list: A pointer to the first element of the linked list to search in
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: A pointer to the first node where value is located
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = 0;
	listint_t *temp, *prev;

	if (list != NULL && size > 0)
	{
		temp = list;
		do {
			prev = temp;
			step = step + sqrt(size);
			while (temp && temp->next && temp->index != step)
				temp = temp->next;
			if (temp->index >= size)
				break;
			printf("Value checked at index [%lu] = [%d]\n", temp->index, temp->n);
		} while (temp && temp->next && temp->n < value && temp->index < size);
		printf("Value found between indexes [%lu] and [%lu]\n", prev->index,
		       temp->index);
		while (prev && prev->index < size)
		{
			printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
			if (prev->n == value)
				return (prev);
			prev = prev->next;
		}
	}
	return (NULL);
}
