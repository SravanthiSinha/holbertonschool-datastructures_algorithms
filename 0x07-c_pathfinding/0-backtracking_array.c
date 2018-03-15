#include "pathfinding.h"

/**
 * map_create_delete - A function that creates/deletes a copy of 2d char array
 * @map: The pointer to a read-only two-dimensional array
 * @rows: no of rows in map
 * @cols: no of columns in map
 * @create: create map if 1 else deletes the map
 * Return: A copy of map allocated if @create or Nothing
 */
char **map_create_delete(char **map, int rows, int cols, int create)
{
	int i = 0, j = 0;
	char **map_cpy = NULL;

	if (create)
	{
		map_cpy = (char **)calloc(rows, sizeof(char *));
		for (i = 0; i < rows && map_cpy; i++)
		{
			map_cpy[i] = (char *)calloc(cols, sizeof(char));
			for (j = 0; j < cols && map_cpy[i]; j++)
				map_cpy[i][j] = map[i][j];
		}
	} else
	{
		for (i = 0; i < rows; i++)
		{
			free(map[i]);
		}
		free(map);
	}
	return (map_cpy);
}

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
 * findpath - A function that searches for the first path from a
 * starting point to a target point within a two-dimensional array
 * @map: The pointer to a two-dimensional array
 * @rows: no of rows in map
 * @cols: no of columns in map
 * @q: Every path in soln is stored in queue
 * @x: current position in map
 * @y: current position in map
 * Return: if path exists 1, else 0
 */
int findpath(char **map, int rows, int cols, queue_t *q, int x, int y)
{
	point_t *curr;

	if (x < 0 || y < 0 || x >= cols || y >= rows)
		/*outside maze */
		return (0);
	if (map[y][x] == GOAL)
	{
		curr = malloc(sizeof(point_t));
		curr->x = x;
		curr->y = y;
		/* reached goal */
		stack_push(q, (void *)curr);
		printf("Checking coordinates [%d, %d]\n", x, y);
		return (1);
	}
	if (map[y][x] != OPEN && map[y][x] != START)
		return (0);
	printf("Checking coordinates [%d, %d]\n", x, y);
	map[y][x] = VISITED;
	curr = malloc(sizeof(point_t));
	curr->x = x;
	curr->y = y;
	stack_push(q, (void *)curr);
	if (findpath(map, rows, cols, q, x + 1, y))	/*right */
		return (1);
	if (findpath(map, rows, cols, q, x, y + 1))	/*below */
		return (1);
	if (findpath(map, rows, cols, q, x - 1, y))	/*left */
		return (1);
	if (findpath(map, rows, cols, q, x, y - 1))	/*top */
		return (1);
	stack_pop(q);
	map[y][x] = BLOCKED;
	return (0);
}

/**
 * backtracking_array - A function that searches for the first path from a
 * starting point to a target point within a two-dimensional array
 * @map: The pointer to a read-only two-dimensional array
 * @rows: no of rows in map
 * @cols: no of columns in map
 * @start: coordinates of the starting point
 * @target: coordinates of the ending point
 * Return: A queue, in which each node is a point in the path from start to
 * target
 */
queue_t *backtracking_array(char **map, int rows, int cols,
			    point_t const *start, point_t const *target)
{
	queue_t *q;
	char **map_cpy;

	q = queue_create();
	map_cpy = map_create_delete(map, rows, cols, 1);
	if (map_cpy)
	{
		map_cpy[start->y][start->x] = START;
		map_cpy[target->y][target->x] = GOAL;
		findpath(map_cpy, rows, cols, q, start->x, start->y);
		map_create_delete(map_cpy, rows, cols, 0);
	}
	if (!q->front)
	{
		free(q);
		q = NULL;
	}

	return (q);
}
