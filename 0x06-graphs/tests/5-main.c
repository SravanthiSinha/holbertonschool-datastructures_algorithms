#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

/**
 * traverse_action - Action to be executed for each visited vertex
 * during traversal
 *
 * @v: Pointer to the visited vertex
 * @depth: Depth of the vertex in graph from vertex 0
 */
void traverse_action(const vertex_t *v, size_t depth)
{
	printf("%*s[%lu] %s\n", (int)depth * 4, "", v->index, v->content);
}

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
		fprintf(stderr, "Failed to create graph\n");
		return (EXIT_FAILURE);
	}

	if (!graph_add_vertex(graph, "San Francisco") ||
	    !graph_add_vertex(graph, "Seattle") ||
	    !graph_add_vertex(graph, "New York") ||
	    !graph_add_vertex(graph, "Miami") ||
	    !graph_add_vertex(graph, "Chicago") ||
	    !graph_add_vertex(graph, "Houston") ||
	    !graph_add_vertex(graph, "Las Vegas") ||
	    !graph_add_vertex(graph, "Boston"))
	{
		fprintf(stderr, "Failed to add vertex\n");
		return (EXIT_FAILURE);
	}

	if (!graph_add_edge(graph, "San Francisco", "Las Vegas", BIDIRECTIONAL)
	    || !graph_add_edge(graph, "Boston", "New York", UNIDIRECTIONAL)
	    || !graph_add_edge(graph, "Miami", "San Francisco", BIDIRECTIONAL)
	    || !graph_add_edge(graph, "Houston", "Seattle", UNIDIRECTIONAL)
	    || !graph_add_edge(graph, "Chicago", "New York", BIDIRECTIONAL)
	    || !graph_add_edge(graph, "Las Vegas", "New York", UNIDIRECTIONAL)
	    || !graph_add_edge(graph, "Seattle", "Chicago", UNIDIRECTIONAL)
	    || !graph_add_edge(graph, "New York", "Houston", BIDIRECTIONAL)
	    || !graph_add_edge(graph, "Seattle", "Miami", BIDIRECTIONAL)
	    || !graph_add_edge(graph, "San Francisco", "Boston", BIDIRECTIONAL))
	{
		fprintf(stderr, "Failed to add edge\n");
		return (EXIT_FAILURE);
	}

	graph_display(graph);

	printf("\nDepth First Traversal:\n");
	depth = breadth_first_traverse(graph, &traverse_action);
	printf("\nDepth: %lu\n", depth);

	graph_delete(graph);

	return (EXIT_SUCCESS);
}
