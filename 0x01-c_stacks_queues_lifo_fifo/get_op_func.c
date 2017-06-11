#include "monty.h"

/**
 * get_op_func - gets the correct operation function realted to operator
 * @c : operator function
 *
 * Return: pointer to operator function
 */
void (*get_op_func(char *c))(stack_t **stack, unsigned int line_number)
{
	int i;
	char *op[3] = {"pall", "pint", "pop"};
	funcPtr p[3] = {
		print_stack,
		print_stack_top,
		pop_stack
	};
	for (i = 0; i < 3; i++)
		if (strstr(c, op[i]) != NULL)
			return (*p[i]);
	return (NULL);
}
