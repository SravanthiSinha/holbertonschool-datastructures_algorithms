/* Description: 2 vertices, 2 edges */

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
		char *city = (char *)dequeue(path);
		printf(" %s\n", city);
		free(city);
	}
	free(path);
}

/**
 * main - A simple graph to test Backtracking algorithm
 *
 * Return: Either EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	graph_t *graph;
	vertex_t *start, *target;
	queue_t *path;

	graph = graph_create();
	start = graph_add_vertex(graph, "Seattle", 0, 0);
	graph_add_vertex(graph, "Houston", 0, 0);
	target = graph_add_vertex(graph, "Miami", 0, 0);
	graph_add_edge(graph, "Seattle", "Houston", 0, BIDIRECTIONAL);
	graph_add_edge(graph, "Seattle", "Miami", 0, BIDIRECTIONAL);

	path = backtracking_graph(graph, start, target);
	if (!path)
	{
		fprintf(stderr, "Failed to retrieve path\n");
		return (EXIT_SUCCESS);
	}

	print_free_path(path);
	graph_delete(graph);

	return (EXIT_SUCCESS);
}
