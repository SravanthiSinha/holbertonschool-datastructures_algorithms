#include <stdio.h>

/**
 * linear_search - A function that searches for a value in an array of
 * integers using the Linear search algorithm
 * @array:  a pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The first index where value is located
 */
int linear_search(int *array, size_t size, int value)
{
	int found = 0;
	unsigned int c = 0;

	if (array != NULL)
	{
		for (c = 0; c < size; c++)
		{
			if (array[c] == value)
			{
				printf("Value checked array[%d] = [%d]\n", c, array[c]);
				found = 1;
				break;
			}
			printf("Value checked array[%d] = [%d]\n", c, array[c]);
		}
	}
	return (found ? (int)c : -1);
}
