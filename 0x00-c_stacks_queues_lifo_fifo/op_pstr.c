#include "monty.h"

/**
 * pstr - Prints ascii of the top of stack
 * @head : stack to be printed
 * @lineno : line no of the instruction
 */
void pstr(stack_t **head, __attribute__((unused)) unsigned int lineno)
{
	stack_t *tmp;

	if (*head != NULL)
	{
		tmp = *head;
		while (tmp && (tmp->n > 0 && tmp->n < 128))
		{
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
	}
	printf("\n");
}
