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
	char *op[2] = {"pint", "pop"};
	funcPtr p[2] = {
		print_stack_top,
		pop_stack
	};
	for (i = 0; i < 2; i++)
		if (strstr(c, op[i]) != NULL)
			return (*p[i]);
	return (NULL);
}
