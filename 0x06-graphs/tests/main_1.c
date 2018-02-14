/* Description: Deletes a graph with 200 vertices, and no edge */

#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"
#include "_names.h"
#include "_edges.h"

/**
 * traverse_action - Action to be executed for each visited vertex
 * during traversal
 *
 * @v: Pointer to the visited vertex
 * @depth: Depth of the vertex in graph from vertex 0
 */
 void traverse_action(const vertex_t *v, size_t depth)
 {
 	printf("(%lu) [%lu] %s\n", depth, v->index, v->content);
 }

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	graph_t *graph;
	size_t i;
	size_t depth = 0;

	graph = graph_create();
	if (!graph)
	{
		printf("Failed to create graph\n");
		return (EXIT_FAILURE);
	}

	for (i = 0; i < NB_NAMES; i++)
	{
		if (!graph_add_vertex(graph, _names[i]))
		{
			printf("Failed to add [%s]\n", _names[i]);
			return (EXIT_FAILURE);
		}
	}
	depth = breadth_first_traverse(graph, &traverse_action);
	printf("\nDepth: %lu\n", depth);

	graph_delete(graph);
	return (EXIT_SUCCESS);
}
