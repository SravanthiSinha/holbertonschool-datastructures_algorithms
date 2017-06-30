#include "search_algos.h"

/**
 * linear_skip -  A function that searches for a value in a sorted skiplist
 * @list: A pointer to the first element of the skip list to search in
 * @value: The value to search for
 * Return: The first index where value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *temp;

	if (list != NULL)
	{
		prev = list;
		list = list->express;
		while (list && list->n < value)
		{
			prev = list;
			list = list->express;
			printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		}
		temp = prev;
		if (prev)
		{
			if (list)
			{
				printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
				printf("Value found between indexes [%lu] and [%lu]\n", prev->index,
				       list->index);
			}
			else
			{
				while (temp->next)
					temp = temp->next;
				printf("Value found between indexes [%lu] and [%lu]\n", prev->index,
				       temp->index);
			}
			while (prev)
			{
				printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
				if (prev->n == value)
					return (prev);
				prev = prev->next;
			}
		}
	}
	return (NULL);
}
