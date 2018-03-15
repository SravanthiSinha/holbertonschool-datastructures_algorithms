/* Description: 3 by 3 map, no obstacle */

#include <stdlib.h>
#include <stdio.h>

#include "pathfinding.h"

/**
 * print_free_path - Unstacks the queue to discover the path from the starting
 * vertex to the target vertex. Also deallocates the queue.
 *
 * @path: Queue containing the path
 */
static void print_free_path(queue_t *path)
{
	printf("Path found:\n");
	while (path->front)
	{
		point_t *point = (point_t *)dequeue(path);
		printf(" [%d, %d]\n", point->x, point->y);
		free(point);
	}
	free(path);
}

#define MAP_SIZE 3

/**
 * main - Backtracking using an array. Here the array is chosen to demonstrate
 * that Backtracking is a really bad algorithm.The target point is just
 * down-right from the startnig point, but seems we first check the right cell,
 * then top, then left, then bottom, our algo will almost go through the whole
 * maze before finding a path.
 * Don't use backtracking. Backtracking is bad.
 */
int main(void)
{
	char *map[MAP_SIZE] = {
		"000",
		"000",
		"000"
	};
	point_t start = { 0, 0 };
	point_t target = { 2, 2 };
	queue_t *path;

	path = backtracking_array((char **)map, MAP_SIZE, MAP_SIZE, &start, &target);
	if (!path)
	{
		fprintf(stderr, "Failed to retrieve path\n");
		return (EXIT_FAILURE);
	}

	print_free_path(path);

	return (EXIT_SUCCESS);
}
