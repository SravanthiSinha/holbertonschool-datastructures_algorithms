#include "monty.h"

/**
 * swap_tops - swaps the top two elements of the stack_t list if list is
 * two elements or long.
 * @head: pointer to head pointer of stack_t list.
 * @lineno: line number of opcode
 * Return: nothing
 **/
void swap_tops(stack_t **head, unsigned int lineno)
{
	int tmp;

	if (!head || !(*head) || !(*head)->next)
	{
		print_error(MONTY_ERROR_STACK_SHORT, lineno, "swap");
		if (*head)
		{
			free(*head);
			*head = NULL;
		}
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
