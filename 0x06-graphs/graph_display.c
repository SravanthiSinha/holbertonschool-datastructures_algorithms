#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

/**
 * graph_display - Utility function to display the adjency linked list
 *
 * @graph: Pointer to the graph structure to be displayed
 */
void graph_display(const graph_t *graph)
{
	vertex_t *v;

	if (!graph)
		return;

	printf("Number of vertices: %lu\n", graph->nb_vertices);
	for (v = graph->vertices; v; v = v->next)
	{
		edge_t *e;

		printf("[%lu] %s", v->index, v->content);
		if (v->edges)
			printf(" ->");
		for (e = v->edges; e; e = e->next)
		{
			if (e->dest)
				printf("%lu", e->dest->index);
			else
				printf("nil");

			if (e->next)
				printf("->");
		}
		printf("\n");
	}
}
