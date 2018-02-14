/* Description: `depth_first_traverse(NULL, &traverse_action);` */

#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"
#include "_names.h"
#include "_edges.h"

/**
 * traverse_action - Action to be executed for each visited vertex
 * during traversal
 *
 * @v: Pointer to the visited vertex
 * @depth: Depth of the vertex in graph from vertex 0
 */
void traverse_action(const vertex_t *v, size_t depth)
{
	printf("(%lu) [%lu] %s\n", depth, v->index, v->content);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	size_t depth;

	depth = breadth_first_traverse(NULL, &traverse_action);
	printf("\nDepth: %lu\n", depth);

	return (EXIT_SUCCESS);
}
