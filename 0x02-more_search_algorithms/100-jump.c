#include "search_algos.h"

/**
 * jump_search -  A function that searches for a value in a sorted array of
 * integers using the Jump search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: The first index where value is located.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t prev = 0, step = 0;

	if (array != NULL && size > 0)
	{
		/* print checking value */
		do {
			prev = step;
			step = step + sqrt(size);
			printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
			if (step >= size)
				break;
		} while (array[step] < value && prev < size);
		/* print bounds */
		printf("Value found between indexes [%lu] and [%lu]\n", prev, step);
		/* print checking value */
		do {
			if (prev >= size)
				break;
			printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
			if (array[prev] == value)
				return (prev);
		} while (array[prev] <= value && prev++ < size);
	}
	return (-1);
}
