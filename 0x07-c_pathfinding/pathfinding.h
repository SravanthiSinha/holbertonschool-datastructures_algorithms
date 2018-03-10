#ifndef _PATHFINDING_H_
#define _PATHFINDING_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queues.h"
#include "graphs.h"

#define OPEN '0'
#define CLOSE '1'
#define BLOCKED 'x'
#define VISITED '+'
#define START 'S'
#define GOAL 'G'

#define  UNEXPLORED '0'
#define  EXPLORED '1'
#define BACKTRACK '2'
/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;

queue_t *backtracking_array(char **map, int rows, int cols,
			    point_t const *start, point_t const *target);
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
			    vertex_t const *target);
#endif
