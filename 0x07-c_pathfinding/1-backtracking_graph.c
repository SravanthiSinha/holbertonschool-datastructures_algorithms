#include "pathfinding.h"

/**
 * stack_push - pushes to the stack
 * @q: stack to be pushed on
 * @x: element to be pushed
 */
void stack_push(queue_t *q, void *x)
{
	queue_push_back(q, x);
}

/**
 * stack_pop - pops the stack
 * @q1: stack to be poped
 */
void stack_pop(queue_t *q1)
{
	void *top = NULL, *p = NULL;
	queue_t *q2, temp;

	if (q1)
	{
		q2 = queue_create();
		top = dequeue(q1);
		if (top)
			p = dequeue(q1);
		while (p)
		{
			queue_push_back(q2, top);
			top = p;
			if (top)
				p = dequeue(q1);
		}
		free(top);
		/*Swap the names of q1 and q2 */
		temp = *q1;
		*q1 = *q2;
		*q2 = temp;
		queue_delete(q2);
	}
}

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
 * findpath - A function that goes through a graph using the
 * depth -first algorithm.
 * @visited: array of nodes marked visited or not
 * @q: path to be stored in queue
 * @graph: A pointer to the graph to traverse
 * @index: current vertex index
 * Return: 1 if path exists else 0
 */
int findpath(char *visited, queue_t *q, const graph_t *graph, size_t index)
{
	char *city;
	vertex_t *curr;
	edge_t *edge;

	curr = get_vertex_index(graph, index);
	if (visited[index] == GOAL)
	{
		city = strdup(curr->content);
		stack_push(q, (void *)city);
		printf("Checking %s\n", city);
		return (1);
	}
	if (visited[index] == VISITED)
		return (0);
	visited[index] = VISITED;
	city = strdup(curr->content);
	stack_push(q, (void *)city);
	printf("Checking %s\n", city);
	edge = curr->edges;
	while (edge && edge->dest)
	{
		if (findpath(visited, q, graph, edge->dest->index))
			return (1);
		edge = edge->next;
	}
	stack_pop(q);
	return (0);
}

/**
 * backtracking_graph - A function that searches for the first path from a
 * starting point to a target point in a graph
 * @graph: The pointer to the graph to go through
 * @start: A pointer to the starting vertex
 * @target: A pointer to the target vertex
 * Return: A queue, in which each node is a point in the path from start to
 * target
 */
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
			    vertex_t const *target)
{
	queue_t *q;
	char *visited;

	if (graph != NULL)
	{
		q = queue_create();
		visited = calloc(graph->nb_vertices, sizeof(char));
		visited[start->index] = START;
		visited[target->index] = GOAL;
		findpath(visited, q, graph, start->index);
		free(visited);
		if (!q->front)
		{
			free(q);
			q = NULL;
		}
	}
	return (q);
}
