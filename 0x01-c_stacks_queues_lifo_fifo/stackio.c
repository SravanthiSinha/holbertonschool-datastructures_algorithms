#include "monty.h"

/**
 * push_stack - Creates the stack and pushes the element to top
 * @stack : stack to be built
 * @n : operand to be added to the stack
 * @lineno : line no of the instruction
 *
 * Return: on malloc Failure: exits with EXIT_FAILURE
 * on sucess returns 1, on failure returns 0
 */
int push_stack(stack_t **stack, char *n, int lineno)
{
	stack_t *temp;
	stack_t *head;

	if (!n || isnum(n) == 0)
	{
		print_error(MONTY_ERROR_INT, lineno, NULL);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	temp = malloc(sizeof(stack_t));

	if (temp != NULL)
	{
		temp->n = atoi(n);
		temp->prev = NULL;
		temp->next = head;
		if (head != NULL)
			head->prev = temp;
		*stack = temp;
		return (1);
	}
	print_error(MONTY_ERROR_MALLOC, 0, NULL);
	exit(EXIT_FAILURE);
}

/**
 * pop_stack - Pops/ deletes the top  elementof stack
 * @stack : stack to be used
 * @lineno : line no of the instruction
 */
void pop_stack(stack_t **stack, unsigned int lineno)
{
	stack_t *next, *node;

	node = *stack;
	if (node == NULL)
	{
		print_error(MONTY_ERROR_STACK_EMPTY, lineno, "pop");
		exit(EXIT_FAILURE);
	}
	else
	{
		next = node->next;
		free(node);
		*stack = next;
	}
}

/**
 * print_stack - Prints  the stack
 * @stack : stack to be printed
 * @lineno : line no of the instruction
 *
 * Return: void
 */
void print_stack(stack_t **stack, __attribute__((unused)) unsigned int lineno)
{
	stack_t *node;

	node = *stack;
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
 */
void print_stack_top(stack_t **stack, unsigned int lineno)
{
	stack_t *node;

	node = *stack;
	if (node != NULL)
		printf("%d\n", node->n);
	else
	{
		print_error(MONTY_ERROR_STACK_EMPTY, lineno, "pint");
		exit(EXIT_FAILURE);
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
