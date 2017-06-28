#include "monty.h"

/**
 * add - adds the top two elements of the stack_t list if list is
 * two elements or long.
 * @head: pointer to head pointer of stack_t list.
 * @lineno: line number of opcode
 * Return: nothing
 **/
void add(stack_t **head, unsigned int lineno)
{
	stack_t *tmp;

	if (!head || !(*head) || !(*head)->next)
	{
		print_error(MONTY_ERROR_STACK_SHORT, lineno, "add");
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
	(*head)->n += tmp->n;
	free(tmp);
}
