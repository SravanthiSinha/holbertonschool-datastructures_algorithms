#include "monty.h"
/**
 * pop_stack - Pops/ deletes the top  elementof head
 * @head : head to be used
 * @lineno : line no of the instruction
 */
void pop_stack(stack_t **head, unsigned int lineno)
{
	stack_t *next, *node;

	node = *head;
	if (node == NULL)
	{
		print_error(MONTY_ERROR_STACK_EMPTY, lineno, "pop");
		exit(EXIT_FAILURE);
	}
	else
	{
		next = node->next;
		free(node);
		*head = next;
	}
}
