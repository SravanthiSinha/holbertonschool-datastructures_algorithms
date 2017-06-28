#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: A stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
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
			*stack = head->next;
			(*stack)->prev = NULL;

			head->prev = tail;
			head->next = NULL;

			tail->next = head;
			break;
		}
		tail = tail->next;
	}
}
