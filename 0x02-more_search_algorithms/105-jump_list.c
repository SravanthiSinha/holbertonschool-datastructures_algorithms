#include "search_algos.h"

/**
 * min - Gets a minimum of 2 values
 * @a: element a
 * @b: element b
 * Return: Minimum of a and b
 */
size_t min(size_t a, size_t b)
{
	return (a < b ? a : b);
}

/**
 * jump_list -  A function that searches for a value in a sorted array of
 * integers using the Jump search algorithm
 * @list: A pointer to the first element of the linked list to search in
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: The first index where value is located.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = 0;
	listint_t *temp, *prev;

	if (list != NULL && size > 0)
	{
		step = sqrt(size);
		temp = list;
		prev = list;
		while (temp && temp->index != step)
			temp = temp->next;
		while (temp && temp->next && temp->n < value && prev->index < size - 1)
		{
			prev = temp;
			step = step + sqrt(size);
			while (temp && temp->next && temp->index != step)
				temp = temp->next;
			printf("Value checked array[%lu] = [%d]\n", prev->index, prev->n);
		}
		if (temp)
			printf("Value checked array[%lu] = [%d]\n", temp->index, temp->n);
		if (prev && temp)
		{
			printf("Value found between indexes [%lu] and [%lu]\n", prev->index,
			       temp->index);
			while (prev && prev->n < value)
			{
				printf("Value checked array[%lu] = [%d]\n", prev->index, prev->n);
				prev = prev->next;
				if (prev && prev->index == min(step, size))
					break;
			}
			if (prev && prev->n == value)
			{
				printf("Value checked array[%lu] = [%d]\n", prev->index, prev->n);
				return (prev);
			}
		}
	}
	return (NULL);
}
