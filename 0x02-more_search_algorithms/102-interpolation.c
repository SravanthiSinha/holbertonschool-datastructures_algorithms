#include "search_algos.h"

/**
 * interpolation_search -  A function that searches for a value in a sorted
 * array of integers using the Interpolation search algorithm.
 *
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 * Return: The first index where value is located.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0, pos = 0, high = size - 1;

	if (array != NULL && size > 0)
	{
		while (array[high] != array[low])
		{
			pos = low + (((double)(high - low) / (array[high] - array[low])) *
				     (value - array[low]));
			if (value > array[high] || value < array[low])
				break;
			printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
			if (array[pos] < value)
				low = pos + 1;
			else if (value < array[pos])
				high = pos - 1;
			else
				return (pos);
		}
		if (value == array[low])
			return (low);
		printf("Value checked array[%lu] is out of range\n", pos);
	}
	return (-1);
}
