#include "monty.h"

/**
 * push - Creates the stack and pushes the element to top
 * @stack : stack to be built
 * @n : int to be added to the stack
 *
 * Return: on malloc Failure: exits with EXIT_FAILURE
 * on sucess returns 0, on failure returns 1
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
		return (0);
	}
	else
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (1);
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
