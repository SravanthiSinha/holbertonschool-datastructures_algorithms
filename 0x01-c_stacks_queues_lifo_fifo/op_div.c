#include "monty.h"

/**
 * div - adds the top two elements of the stack_t list if list is
 * two elements or long.
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
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	if ((*head)->n  != 0)
		(*head)->n = tmp->n / (*head)->n;
	else
		print_error(MONTY_ERROR_DIV_BY_ZERO, lineno, NULL);
	free(tmp);
}
