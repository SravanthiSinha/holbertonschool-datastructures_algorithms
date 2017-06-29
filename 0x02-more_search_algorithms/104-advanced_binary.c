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

	if (l <= r)
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
		if (arr[mid] == x && arr[mid - 1] != x)
			return (mid);
		if (arr[mid] >= x)
			return (binarySearch(arr, l, mid, x));
		return (binarySearch(arr, mid + 1, r, x));
	}
	return (-1);
}

/**
 * advanced_binary -  A function that searches for a value in a sorted
 * array of integers using the Interpolation search algorithm.
 *
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @x: The value to search for
 * Return: The first index where value is located.
 */
int advanced_binary(int *array, size_t size, int x)
{
	if (array != NULL && size > 0)
		return (binarySearch(array, 0, size - 1, x));
	return (-1);
}
