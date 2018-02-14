#ifndef _GRAPHS_H_
#define  _GRAPHS_H_

#include <malloc.h>
#include <string.h>
#include <limits.h>

#define  SUCCESS 1
#define  FAILURE 0
#define  UNEXPLORED 0
#define  EXPLORED 1
#define BACKTRACK 2
#define SIZE 65536
#define LEVELBREAK -60
/**
 * enum edge_type_e - Enumerates the different types of
 * connection between two vertices
 *
 * @UNIDIRECTIONAL: The connection is made only in one way
 * @BIDIRECTIONAL: The connection is made in two ways
 */
typedef enum edge_type_e
{
	UNIDIRECTIONAL = 0,
	BIDIRECTIONAL
} edge_type_t;

/* Define the structure temporarily for usage in the edge_t */
typedef struct vertex_s vertex_t;

/**
 * struct edge_s - Node in the linked list of edges for a given vertex
 * A single vertex can have many edges
 *
 * @dest: Pointer to the connected vertex
 * @next: Pointer to the next edge
 */
typedef struct edge_s
{
	vertex_t *dest;
	struct edge_s *next;
} edge_t;

/**
 * struct vertex_s - Node in the linked list of vertices in the adjency list
 *
 * @index: Index of the vertex in the adjency list.
 * @content: Custom data stored in the vertex (here, a string)
 * @nb_edges: Number of conenctions with other vertices in the graph
 * @edges: Pointer to the head node of the linked list of edges
 * @next: Pointer to the next vertex in the adgency linked list
 *   This pointer points to another vertex in the graph, but it
 *   doesn't stand for an edge between the two vertices
 */
struct vertex_s
{
	size_t index;
	char *content;
	size_t nb_edges;
	edge_t *edges;
	struct vertex_s *next;
};

/**
 * struct graph_s - Representation of a graph
 * We use an adjency linked list to represent our graph
 *
 * @nb_vertices: Number of vertices in our graph
 * @vertices: Pointer to the head node of our adjency linked list
 */
typedef struct graph_s
{
	size_t nb_vertices;
	vertex_t *vertices;
} graph_t;

/**
 * struct queue_s - Representation of a queue
 *
 * @items: items to be queued
 * @front: Pointer to the first item in queue
 * @rear: Pointer to the last item in queue
 */
typedef struct queue_s
{
	int items[SIZE];
	int front;
	int rear;
} queue_t;

void graph_display(const graph_t *graph);
graph_t *graph_create(void);
vertex_t *graph_add_vertex(graph_t *graph, const char *str);
int graph_add_edge(graph_t *g, const char *s, const char *d, edge_type_t t);
void graph_delete(graph_t *graph);
size_t depth_first_traverse(const graph_t *graph,
			    void (*action)(const vertex_t *v, size_t depth));
size_t breadth_first_traverse(const graph_t *graph,
			      void (*action)(const vertex_t *v,
					      size_t depth));
#endif
