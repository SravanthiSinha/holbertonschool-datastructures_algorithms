#include "graphs.h"

/**
 * graph_create_vertex - A function that allocates memory to creates a vertex
 * structure, and initializes its content.
 * @str: The string to store in the new vertex
 * Return:  A pointer to the allocated structure, or NULL on failure
 */
vertex_t *graph_create_vertex(const char *str)
{
	vertex_t *v;

	v = malloc(sizeof(vertex_t));

	if (v == NULL)
		return (NULL);
	v->index = 0;
	v->content = strdup(str);
	v->edges = NULL;
	v->nb_edges = 0;
	v->next = NULL;
	return (v);
}

/**
 * graph_add_vertex - A function that adds a vertex to an existing graph
 *
 * @graph: A pointer to the graph to add the vertex to
 * @str: The string to store in the new vertex
 * Return: A pointer to the created vertex, or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new_vertix, *node, *prev;
	size_t count = 0;

	if (graph == NULL || str == NULL)
		return (NULL);

	node = graph->vertices;
	while (node != NULL)
	{
		if (strcmp(node->content, str) == 0)
		{
			return (NULL);
		}
		prev = node;
		node = node->next;
		count++;
	}
	new_vertix = graph_create_vertex(str);
	if (new_vertix == NULL)
		return (NULL);
	if (graph->nb_vertices == 0)

		graph->vertices = new_vertix;
	else

		prev->next = new_vertix;

	new_vertix->index = count;
	graph->nb_vertices += 1;

	return (new_vertix);
}
