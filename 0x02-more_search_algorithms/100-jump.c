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
		step = sqrt(size);
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		while (array[min(step, size)] < value && prev < size - 1)
		{
			prev = step;
			step = step + sqrt(size);
			printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		}
		printf("Value found between indexes [%lu] and [%lu]\n", prev, step);
		while (array[prev] < value)
		{
			printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
			prev++;
			if (prev == min(step, size))
				break;
		}
		if (array[prev] == value)
		{
			printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
			return (prev);
		}
	}
	return (-1);
}
