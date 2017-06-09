#include "monty.h"

/**
 * push - Creates the stack and pushes the element to top
 * @stack : stack to be built
 * @n : int to be added to the stack
 *
 * Return: on malloc Failure: exits with EXIT_FAILURE
 * on sucess returns 1, on failure returns 0
 */
int push(stack_t **stack, int n)
{
	stack_t *temp;
	stack_t *head;

	head = *stack;
	temp = malloc(sizeof(stack_t));

	if (temp != NULL)
	{
		temp->n = n;
		temp->prev = NULL;
		temp->next = head;
		if (head != NULL)
			head->prev = temp;
		*stack = temp;
		return (1);
	}
		printf("Error: malloc failed\n");
		return (0);

}

/**
 * print_stack - Prints  the stack
 * @stack : stack to be printed
 *
 * Return: void
 */
void print_stack(stack_t *stack)
{
	stack_t *node;

	node = stack;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * print_stack_top - Prints  the top of stack
 * @stack : stack to be printed
 * @lineno : line no of the instruction
 *
 * Return: on sucess returns 1, on failure returns 0
 */
int print_stack_top(stack_t *stack, int lineno)
{
	stack_t *node;

	node = stack;
	if (node != NULL)
	{
		printf("%d\n", node->n);
		return (1);
	}
	printf("L%d: can't pint, stack empty\n", lineno);
	return (0);
}

/**
 * free_stack - Frees  the stack
 * @stack : stack to be freed
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *node;
	stack_t *curr;

	node = stack;
	while (node)
	{
		curr = node;
		node = node->next;
		free(curr);
	}
}
