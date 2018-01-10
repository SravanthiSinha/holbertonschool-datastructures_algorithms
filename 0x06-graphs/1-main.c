#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"
void graph_display(const graph_t *graph);
/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	graph_t *graph;

	graph = graph_create();
	if (!graph)
	{
		fprintf(stderr, "Failed to create graph\n");
		return (EXIT_FAILURE);
	}

	if (!graph_add_vertex(graph, "San Francisco"))
	{
		fprintf(stderr, "Failed to add vertex\n");
		return (EXIT_FAILURE);
	}

	graph_display(graph);

	if (!graph_add_vertex(graph, "Seattle") ||
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

	graph_display(graph);

	if (!graph_add_vertex(graph, "San Francisco"))
		fprintf(stderr, "Failed to add \"San Francisco\"\n");
	if (!graph_add_vertex(graph, "Boston"))
		fprintf(stderr, "Failed to add \"Boston\"\n");

	return (EXIT_SUCCESS);
}
