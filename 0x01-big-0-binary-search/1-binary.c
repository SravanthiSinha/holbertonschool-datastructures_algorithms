#include "search_algos.h"

/**
 * print_array - print array elements on single line
 * @array: array to print.
 * @start: start of array.
 * @end: end of array.
 * Return: void
 */
void print_array(int *array, size_t start, size_t end)
{
	printf("Searching in array: ");
	while (start < end)
	{
		printf("%d, ", array[start]);
		++start;
	}
	printf("%d\n", array[start]);
}

/**
 * binary_search - A function that searches for a value in an array of
 * integers using the Binary search algorithm
 * @array:  a pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The first index where value is located
 */
int binary_search(int *array, size_t size, int value)
{
	size_t start, end, mid;

	if (!array)
		return (-1);
	start = 0;
	end = size - 1;
	while (start <= end)
	{
		print_array(array, start, end);
		mid = (start + end) / 2;
		if (value == array[mid])
			return (mid);
		if (value > array[mid])
			start = mid + 1;
		else
			end = mid;
	}
	return (-1);
}
