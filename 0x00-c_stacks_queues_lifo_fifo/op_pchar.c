#include "monty.h"

/**
 * pchar - Prints ascii of the top of stack
 * @stack : stack to be printed
 * @lineno : line no of the instruction
 */
void pchar(stack_t **stack, unsigned int lineno)
{
	stack_t *node;

	node = *stack;
	if (node != NULL)
	{
		if (node->n >= 0 && node->n <= 127)
			printf("%c\n", node->n);
		else
		{
			print_error(MONTY_ERROR_OUT_OF_RANGE, lineno, "pchar");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		print_error(MONTY_ERROR_STACK_EMPTY, lineno, "pchar");
		exit(EXIT_FAILURE);
	}
}
