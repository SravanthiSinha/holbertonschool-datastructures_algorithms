#include <stdlib.h>
#include <stdio.h>

#include "pathfinding.h"

/**
 * print_free_path - Unstacks the queue to discover the path from the starting
 * vertex to the target vertex. Also deallocates the queue.
 *
 * @path: Queue containing the path
 */
static void print_free_path(queue_t *path)
{
    printf("Path found:\n");
    while (path->front)
    {
        char *city = (char *)dequeue(path);
        printf(" %s\n", city);
        free(city);
    }
    free(path);
}

/**
 * main - Another example to demonstrate the weakness of Dijkstra's algorithm
 * In fact, Dijkstra's algorithm will always choose the shortest path from
 * the starting vertex.
 * In this example, the target vertex is just the neighbour of the starting
 * vertex, but the distance between them is very big. Dijkstra's algorithm will
 * then go through all the vertices, to finally fall back to the target vertex.
 *
 * Return: Either EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;
    vertex_t *start, *target;
    queue_t *path;

    graph = graph_create();
    start = graph_add_vertex(graph, "A", 0, 0);
    target = graph_add_vertex(graph, "B", 0, 0);
    graph_add_vertex(graph, "C", 0, 0);
    graph_add_vertex(graph, "D", 0, 0);
    graph_add_vertex(graph, "E", 0, 0);
    graph_add_vertex(graph, "F", 0, 0);
    graph_add_vertex(graph, "G", 0, 0);
    graph_add_vertex(graph, "H", 0, 0);
    graph_add_vertex(graph, "I", 0, 0);
    graph_add_vertex(graph, "J", 0, 0);
    graph_add_vertex(graph, "K", 0, 0);
    graph_add_vertex(graph, "L", 0, 0);
    graph_add_vertex(graph, "M", 0, 0);
    graph_add_vertex(graph, "N", 0, 0);
    graph_add_vertex(graph, "O", 0, 0);

    graph_add_edge(graph, "A", "B", 1000, BIDIRECTIONAL);
    graph_add_edge(graph, "A", "C", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "C", "D", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "D", "E", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "E", "F", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "F", "G", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "G", "H", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "H", "I", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "I", "J", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "J", "K", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "K", "L", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "L", "M", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "M", "N", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "N", "O", 10, BIDIRECTIONAL);

    path = dijkstra_graph(graph, start, target);
    if (!path)
    {
        fprintf(stderr, "Failed to retrieve path\n");
        return (EXIT_FAILURE);
    }

    print_free_path(path);
    graph_delete(graph);

    return (EXIT_SUCCESS);
}
