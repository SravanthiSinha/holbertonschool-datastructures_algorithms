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
 * main - A simple graph to test A* algorithm
 *
 * Return: Either EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;
    vertex_t *start, *target;
    queue_t *path;

    graph = graph_create();
    graph_add_vertex(graph, "San Francisco", 37, -122);
    graph_add_vertex(graph, "Los Angeles", 34, -118);
    graph_add_vertex(graph, "Las Vegas", 36, -115);
    start = graph_add_vertex(graph, "Seattle", 47, -122);
    graph_add_vertex(graph, "Chicago", 41, -87);
    graph_add_vertex(graph, "Washington", 38, -77);
    graph_add_vertex(graph, "New York", 40, -74);
    graph_add_vertex(graph, "Houston", 29, -95);
    graph_add_vertex(graph, "Nashville", 36, -86);
    target = graph_add_vertex(graph, "Miami", 25, -80);
    graph_add_edge(graph, "San Francisco", "Los Angeles", 347, BIDIRECTIONAL);
    graph_add_edge(graph, "San Francisco", "Las Vegas", 417, BIDIRECTIONAL);
    graph_add_edge(graph, "Los Angeles", "Las Vegas", 228, BIDIRECTIONAL);
    graph_add_edge(graph, "San Francisco", "Seattle", 680, BIDIRECTIONAL);
    graph_add_edge(graph, "Seattle", "Chicago", 1734, BIDIRECTIONAL);
    graph_add_edge(graph, "Chicago", "Washington", 594, BIDIRECTIONAL);
    graph_add_edge(graph, "Washington", "New York", 203, BIDIRECTIONAL);
    graph_add_edge(graph, "Las Vegas", "Houston", 1227, BIDIRECTIONAL);
    graph_add_edge(graph, "Houston", "Nashville", 666, BIDIRECTIONAL);
    graph_add_edge(graph, "Nashville", "Washington", 566, BIDIRECTIONAL);
    graph_add_edge(graph, "Nashville", "Miami", 818, BIDIRECTIONAL);

    path = a_star_graph(graph, start, target);
    if (!path)
    {
        fprintf(stderr, "Failed to retrieve path\n");
        return (EXIT_FAILURE);
    }

    print_free_path(path);
    graph_delete(graph);

    return (EXIT_SUCCESS);
}
