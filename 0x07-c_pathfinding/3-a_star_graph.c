#include "math.h"
#include "pathfinding.h"

#define Euclidean(x1, y1, x2, y2)  (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)))

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
 * tentative gScoreance among the nodes in the unvisited
 * @graph: A pointer to the graph
 * @fScore:  The array to track the fScores
 * @v: The array to track if vertex is visited or not
 * @index: The index with minimun identifying the vertex with minimum
 * tentative gScoreance
 *
 * Return: minimum tentative gScoreance among the nodes in the unvisited
 */
size_t get_smallest(graph_t *graph, size_t *fScore, size_t *v, size_t *index)
{
	size_t min = INF;
	size_t *a = fScore;
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
 * @cameFrom: The array to track cameFroms of vertices
 * @start: A pointer to the starting vertex
 * @target: A pointer to the target vertex
 *
 * Return: Nothing
 */
void loadQueue(graph_t *graph, queue_t *q, char **cameFrom,
	       vertex_t const *start, vertex_t const *target)
{
	size_t i = 0, t = 0;
	vertex_t *v;

	t = target->index;
	if (cameFrom[t])
	{
		queue_push_front(q, strdup(target->content));
		while (strcmp(cameFrom[t], start->content))
		{
			queue_push_front(q, strdup(cameFrom[t]));
			v = graph->vertices;
			for (i = 0; i < V && v; i++)
			{
				if (strcmp(v->content, cameFrom[t]) == 0)
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
 * @cameFrom: The array to track cameFroms of vertices
 * @gScore:  The array to track the distances from start to a vertex
 * @fScore:  The array to track the Euclidean distances from start to a vertex
 * @start: A pointer to the starting vertex
 * @target: A pointer to the target vertex
 * @index: index of a current vertex tracked
 */
void findShortestPath(graph_t *graph, size_t *visited, char **cameFrom,
		      size_t *gScore, size_t *fScore, const vertex_t *start,
		      const vertex_t *target, size_t index)
{
	vertex_t *curr, *neighbour;
	edge_t *edge;
	size_t smallest, tentative_gScore;

	smallest = INF;
	curr = get_vertex_index(graph, index);
	if (!curr)
		return;
	edge = curr->edges;
	printf("Checking %s, distance to %s is %ld\n", curr->content,
	       target->content, (size_t) Euclidean(curr->x, curr->y, target->x,
						   target->y));
	/*For the current node, consider all of its unvisited neighbors */
	while (edge && visited[index] == UNEXPLORED)
	{
		neighbour = edge->dest;
		if (neighbour)
		{
			tentative_gScore = gScore[index] + edge->weight;
			if (gScore[neighbour->index] >= tentative_gScore)
			{
				gScore[neighbour->index] = tentative_gScore;
				fScore[neighbour->index] = gScore[neighbour->index] +
				    Euclidean(neighbour->x, neighbour->y, target->x, target->y);
				if (cameFrom[neighbour->index])
				{
					free(cameFrom[neighbour->index]);
					cameFrom[neighbour->index] = NULL;
				}
				cameFrom[neighbour->index] = strdup(curr->content);
			}
		}
		edge = edge->next;
	}
	visited[index] = EXPLORED;
	smallest = get_smallest(graph, fScore, visited, &index);
	if (visited[target->index] == EXPLORED || smallest == INF)
		return;
	findShortestPath(graph, visited, cameFrom, gScore, fScore, start,
			 target, index);
}

/**
 * a_star_graph - A function that searches for the shortest cameFrom from a
 * starting point to a target point in a graph using A-star algorithm
 * @graph: The pointer to the graph to go through
 * @start: A pointer to the starting vertex
 * @target: A pointer to the target vertex
 * Return: A queue, in which each node is a point in the cameFrom from start to
 * target
 */
queue_t *a_star_graph(graph_t *graph, vertex_t const *start,
		      vertex_t const *target)
{
	queue_t *q;
	size_t *gScore, i, *visited, *fScore;
	char **cameFrom;

	if (graph != NULL)
	{
		q = queue_create();
		visited =
		    (size_t *) malloc(graph->nb_vertices * sizeof(size_t));
		cameFrom = (char **)malloc(graph->nb_vertices * sizeof(char *));
		gScore = (size_t *) malloc(graph->nb_vertices * sizeof(size_t));
		fScore = (size_t *) malloc(graph->nb_vertices * sizeof(size_t));
		for (i = 0; i < graph->nb_vertices; i++)
		{
			gScore[i] = INF;
			fScore[i] = INF;	/*Assign to every node a tentative distance  value */
			visited[i] = UNEXPLORED;	/*Mark all nodes visited. */
			cameFrom[i] = NULL;
		}
		gScore[start->index] = 0;	/*cost of going from start to start is zero. */
		fScore[start->index] =
		    Euclidean(start->x, start->y, target->x, target->y);
		findShortestPath(graph, visited, cameFrom, gScore, fScore,
				 start, target, start->index);
		loadQueue(graph, q, cameFrom, start, target);
		free(visited);
		free(gScore);
		free(fScore);
		for (i = 0; i < graph->nb_vertices; i++)
		{
			free(cameFrom[i]);
		}
		free(cameFrom);
		if (!q->front)
		{
			free(q);
			q = NULL;
		}
	}
	return (q);
}
