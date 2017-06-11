#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: A stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head, *tail;

	head = *stack;
	tail = head;
	while (tail)
	{
		if (tail == head && tail->next == NULL)
		{
			break;
		}

		if (tail->next == NULL)
		{
			tail->prev->next = NULL;
			tail->next = head;
			tail->prev = NULL;

			head->prev = tail;
			*stack = tail;
			break;
		}
		tail = tail->next;
	}
}
