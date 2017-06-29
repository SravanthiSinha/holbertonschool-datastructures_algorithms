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
 * binarySearch -  A Recursive binary search
 *
 * @arr: A pointer to the first element of the array to search in
 * @l: Left / lower bound
 * @r: Right / upper bound
 * @x: The value to search for
 * Return: The first index where value is located.
 */
int binarySearch(int *arr, size_t l, size_t r, int x)
{
	size_t i, mid;

	if (r >= l)
	{
		printf("Searching in array: ");
		for (i = l; i <= r; i++)
		{
			if (i == r)
				printf("%d\n", arr[i]);
			else
				printf("%d, ", arr[i]);
		}
		mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return (mid);
		if (arr[mid] > x)
			return (binarySearch(arr, l, mid - 1, x));
		return (binarySearch(arr, mid + 1, r, x));
	}
	return (-1);
}

/**
 * exponential_search -  A function that searches for a value in a sorted
 * array of integers using the Exponential search algorithm.
 *
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @x: The value to search for
 * Return: The first index where value is located.
 */
int exponential_search(int *array, size_t size, int x)
{
	size_t i = 1;

	if (array != NULL && size > 0)
	{
		if (array[0] == x)
			return (0);
		while (i < size && array[i] <= x)
		{
			printf("Value checked array[%lu] = [%d]\n", i, array[i]);
			i = i * 2;
		}
		printf("Value found between indexes [%lu] and [%lu]\n", i / 2,
		       min(i, size - 1));
		return (binarySearch(array, i / 2, min(i, size - 1), x));
	}
	return (-1);
}
