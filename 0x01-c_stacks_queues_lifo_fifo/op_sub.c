#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element
 * of the stack
 * @head: pointer to head pointer of stack_t list.
 * @lineno: line number of opcode
 * Return: nothing
 **/
void sub(stack_t **head, unsigned int lineno)
{
	stack_t *tmp;

	if (!head || !(*head) || !(*head)->next)
	{
		print_error(MONTY_ERROR_STACK_SHORT, lineno, "sub");
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
	(*head)->n -= tmp->n;
	free(tmp);
}
