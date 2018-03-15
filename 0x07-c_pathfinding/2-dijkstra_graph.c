#include "pathfinding.h"

/**
 * get_vertex_index - A function that fetches an vertex existing in graph by
 * name
 * @graph: A pointer to the graph
 * @index: The index identifying the vertex
 *
 * Return: vertex on success,  NULL on failure
 */
vertex_t *get_vertex_index(const graph_t *graph, size_t index)
{
	vertex_t *node;

	if (index > graph->nb_vertices)
		return (NULL);
	node = graph->vertices;
	if (node == NULL)
		return (NULL);
	while (node != NULL)
	{
		if (node->index == index)
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

/**
 * get_smallest - A function that fetches index of vertex with smallest
 * tentative distance among the nodes in the unvisited
 * @graph: A pointer to the graph
 * @dist:  The array to track the distances from start to a vertex
 * @v: The array to track if vertex is visited or not
 * @index: The index with minimun identifying the vertex with minimum
 * tentative distance
 *
 * Return: minimum tentative distance among the nodes in the unvisited
 */
size_t get_smallest(graph_t *graph, size_t *dist, size_t *v, size_t *index)
{
	size_t min = INFINITY;
	size_t *a = dist;
	size_t i = 0;

	while (i < V)
	{
		if (*a < min && v[i] == UNEXPLORED)
		{
			min = *a;
			*index = i;
		}
		a++;
		i++;
	}
	return (min);
}

/**
 * loadQueue - A function that loads the queue with vertices of shortest path
 * @graph: A pointer to the graph
 * @q: queue to be filled in
 * @parent: The array to track parents of vertices
 * @start: A pointer to the starting vertex
 * @target: A pointer to the target vertex
 *
 * Return: Nothing
 */
void loadQueue(graph_t *graph, queue_t *q, char **parent,
	       vertex_t const *start, vertex_t const *target)
{
	size_t i = 0, t = 0;
	vertex_t *v;

	t = target->index;
	if (parent[t] || parent[start->index])
	{
		queue_push_front(q, strdup(target->content));
		while (strcmp(parent[t], start->content))
		{
			queue_push_front(q, strdup(parent[t]));
			v = graph->vertices;
			for (i = 0; i < V && v; i++)
			{
				if (strcmp(v->content, parent[t]) == 0)
				{
					t = i;
					break;
				}
				v = v->next;
			}
		}
		queue_push_front(q, strdup(start->content));
	}
}

/**
 * findShortestPath - A function that searches for the shortest path from a
 * starting point to a target point in a graph using dijkstra algorithm
 * @graph: The pointer to the graph to go through
 * @visited: The array to track if vertex is visited or not
 * @parent: The array to track parents of vertices
 * @dist:  The array to track the distances from start to a vertex
 * @start: A pointer to the starting vertex
 * @target: A pointer to the target vertex
 * @index: index of a current vertex tracked
 */
void findShortestPath(graph_t *graph, size_t *visited, char **parent,
		      size_t *dist, const vertex_t *start,
		      const vertex_t *target, size_t index)
{
	vertex_t *curr, *child;
	edge_t *edge;
	size_t smallest = INFINITY, alt;

	curr = get_vertex_index(graph, index);
	if (!curr)
		return;
	edge = curr->edges;
	printf("Checking %s, distance from %s is %ld\n", curr->content,
	       start->content, dist[index]);
	/*For the current node, consider all of its unvisited neighbors */
	while (edge && visited[index] == UNEXPLORED)
	{
		child = edge->dest;
		alt = dist[index] + edge->weight;
		if (child && (dist[child->index] > alt))
		{
			dist[child->index] = dist[index] + edge->weight;
			if (parent[child->index])
			{
				free(parent[child->index]);
				parent[child->index] = NULL;
			}
			parent[child->index] = strdup(curr->content);
		}
		edge = edge->next;
	}
	visited[index] = EXPLORED;
	smallest = get_smallest(graph, dist, visited, &index);
	if (visited[target->index] == EXPLORED || smallest == INFINITY)
		return;

	findShortestPath(graph, visited, parent, dist, start, target,
			 index);
}


/**
 * dijkstra_graph - A function that searches for the shortest parent from a
 * starting point to a target point in a graph
 * @graph: The pointer to the graph to go through
 * @start: A pointer to the starting vertex
 * @target: A pointer to the target vertex
 * Return: A queue, in which each node is a point in the parent from start to
 * target
 */
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
			vertex_t const *target)
{
	queue_t *q;
	size_t *dist, i, *visited;
	char **parent;

	if (graph != NULL)
	{
		q = queue_create();
		visited = (size_t *)malloc(graph->nb_vertices * sizeof(size_t));
		parent = (char **)malloc(graph->nb_vertices * sizeof(char *));
		dist = (size_t *) malloc(graph->nb_vertices * sizeof(size_t));
		for (i = 0; i < graph->nb_vertices; i++)
		{
			dist[i] = INFINITY;	/*Assign to every node a tentative distance value */
			visited[i] = UNEXPLORED;	/*Mark all nodes visited. */
			parent[i] = NULL;
		}
		dist[start->index] = 0;
		findShortestPath(graph, visited, parent, dist, start, target,
				 start->index);
		loadQueue(graph, q, parent, start, target);
		free(visited);
		free(dist);
		for (i = 0; i < graph->nb_vertices; i++)
		{
			free(parent[i]);
		}
		free(parent);
		if (!q->front)
		{
			free(q);
			q = NULL;
		}
	}
	return (q);
}
