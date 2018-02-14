/* Description: `depth_first_traverse(graph, NULL);` */

#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"
#include "_names.h"
#include "_edges.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	graph_t *graph;
	size_t depth;

	graph = graph_create();
	if (!graph)
	{
		printf("Failed to create graph\n");
		return (EXIT_FAILURE);
	}

	depth = breadth_first_traverse(graph, NULL);
	printf("\nDepth: %lu\n", depth);

	graph_delete(graph);

	return (EXIT_SUCCESS);
}
