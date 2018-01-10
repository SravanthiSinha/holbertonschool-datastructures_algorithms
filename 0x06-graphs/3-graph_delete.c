#include "graphs.h"

/**
 * graph_delete - A function that completely deletes a graph
 * @graph: A pointer to the graph
 */
void graph_delete(graph_t *graph)
{
	vertex_t *t_vertex = NULL;
	edge_t *t_edge = NULL;

	if (graph == NULL)
		return;
	while (graph->vertices != NULL)
	{
		while (graph->vertices->edges != NULL)
		{
			t_edge = graph->vertices->edges;
			graph->vertices->edges = graph->vertices->edges->next;
			free(t_edge);
		}
		t_vertex = graph->vertices;
		graph->vertices = graph->vertices->next;
		free(t_vertex->content);
		free(t_vertex);
		graph->nb_vertices -= 1;
	}
	free(graph);
	graph = NULL;
}
