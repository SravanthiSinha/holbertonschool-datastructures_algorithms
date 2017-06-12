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
void push_stack(stack_t **stack, char *n, int lineno)
{
	if (!n || isnum(n) == 0)
	{
		print_error(MONTY_ERROR_INT, lineno, NULL);
		exit(EXIT_FAILURE);
	}

	flag == 0 ?  add_front(stack, atoi(n)) : add_end(stack, atoi(n));

}
/**
* add_front - add a new node in the begining of stack_t list.
* @head: pointer to head pointer of the list
* @data: new node data
* Return: address of new node
**/
stack_t *add_front(stack_t **head, int data)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->prev = NULL;
	new->next = *head;
	*head = new;
	return (new);
}

/**
* add_end - add a new node in the end of stack_t list.
* @head: pointer to head pointer of the list
* @data: new node data
* Return: address of new node
**/
stack_t *add_end(stack_t **head, int data)
{
	stack_t *new, *tmp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->prev = NULL;
	new->next = NULL;
	if (!(*head))
		*head = new;
	else if (!(*head)->next)
	{
		(*head)->next = new;
		new->prev = *head;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (new);
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
