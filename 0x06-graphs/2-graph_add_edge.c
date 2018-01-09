#include "graphs.h"

/**
 * get_vertex - A function that fetches an vertex existing in graph
 * @graph: A pointer to the graph
 * @str: The string identifying the vertex
 *
 * Return: vertex on success,  NULL on failure
 */
vertex_t *get_vertex(graph_t *graph, const char *str)
{
	vertex_t *node;

	if (str == NULL)
		return (FAILURE);
	node = graph->vertices;
	if (node == NULL)
		return (NULL);
	while (node != NULL)
	{
		if (strcmp(node->content, str) == 0)
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

/**
 * create_edge -  A function that creates an edge between two vertices
 * @src: The src vertex to make the connection from
 * @dest: The destination vertex to connect to
 *
 * Return: 1 on success,  0 on failure
 */
int create_edge(vertex_t *src, vertex_t *dest)
{
	edge_t *edge, *new_edge = NULL;

	edge = src->edges;
	while (edge && edge->next != NULL)
	{
		edge = edge->next;
	}

	new_edge = malloc(sizeof(edge_t));
	if (new_edge != NULL)
	{
		new_edge->dest = dest;
		new_edge->next = NULL;

		if (src->nb_edges == 0)
			src->edges = new_edge;
		else
			edge->next = new_edge;
		return (SUCCESS);
	}
	return (FAILURE);
}

/**
 * edge_exists -  A function that checks if an edge between two vertices
 * @src: The src vertex to make the connection from
 * @dest: The destination vertex to connect to
 *
 * Return: 1 if exists,  0 if not exists
 */
int edge_exists(vertex_t *src, vertex_t *dest)
{
	edge_t *edge = NULL;

	edge = src->edges;
	while (edge != NULL)
	{
		if (edge->dest == dest)
			return (SUCCESS);
		edge = edge->next;
	}

	return (FAILURE);
}

/**
 * graph_add_edge -  A function that adds an edge between two vertices to an
 * existing graph
 * @graph: A pointer to the graph to add the edge to
 * @s: The string identifying the vertex to make the connection from
 * @d: The string identifying the vertex to connect to
 * @type: the type of edge
 * UNIDIRECTIONAL: Only one edge is created connecting src to dest
 * BIDIRECTIONAL: Two edges are created, connecting src to dest AND dest to src
 *
 * Return: 1 on success, or 0 on failure
 */
int graph_add_edge(graph_t *graph, const char *s, const char *d,
		   edge_type_t type)
{
	vertex_t *src, *dest;

	if (graph == NULL || (type != UNIDIRECTIONAL && type != BIDIRECTIONAL))
		return (FAILURE);
	src = get_vertex(graph, s);
	dest = get_vertex(graph, d);
	if (!src || !dest)
		return (FAILURE);

	if (type == UNIDIRECTIONAL || type == BIDIRECTIONAL)
	{
		if (edge_exists(src, dest))
			return (SUCCESS);
		if (!create_edge(src, dest))
			return (FAILURE);
		src->nb_edges += 1;
	}
	if (type == BIDIRECTIONAL)
	{
		if (edge_exists(dest, src))
			return (SUCCESS);
		if (!create_edge(dest, src))
			return (FAILURE);
		dest->nb_edges += 1;
	}
	return (SUCCESS);
}
