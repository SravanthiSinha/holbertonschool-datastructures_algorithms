#include "monty.h"

/**
 * div - divides the second top element of the stack by the top
 * element of the stack
 * @head: pointer to head pointer of stack_t list.
 * @lineno: line number of opcode
 * Return: nothing
 **/
void divide(stack_t **head, unsigned int lineno)
{
	stack_t *tmp;

	if (!head || !(*head) || !(*head)->next)
	{
		print_error(MONTY_ERROR_STACK_SHORT, lineno, "div");
		if (*head)
		{
			free(*head);
			*head = NULL;
		}
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		print_error(MONTY_ERROR_DIV_BY_ZERO, lineno, NULL);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	(*head)->n /= tmp->n;
	free(tmp);
}
