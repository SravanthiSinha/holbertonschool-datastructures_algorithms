#include "monty.h"

/**
 * print_stack_top - Prints  the top of head
 * @head : head to be printed
 * @lineno : line no of the instruction
 */
void print_stack_top(stack_t **head, unsigned int lineno)
{
	stack_t *node;

	node = *head;
	if (node != NULL)
		printf("%d\n", node->n);
	else
	{
		print_error(MONTY_ERROR_STACK_EMPTY, lineno, "pint");
		exit(EXIT_FAILURE);
	}
}
