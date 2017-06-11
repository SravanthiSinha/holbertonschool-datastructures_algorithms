#include "monty.h"

/**
 * monty_execute - Executes an instruction set based on the opcode
 * @stack : stack to be built
 * @tokens : opcode and operand
 * @lineno : The line no of the instruction set.
 *
 * Return: On success - 1, on failure 0
 */
int monty_execute(stack_t **stack, char **tokens, unsigned int lineno)
{
	instruction_t fun[] = {
		{ "pall", &print_stack },
		{ "pint", &print_stack_top },
		{ "pop", &pop_stack },
		{ "swap", &swap_tops },
		{ NULL, NULL }
	};
	int i;

	if (strcmp(tokens[0], "push") == 0) /* contains push*/
	{
		push_stack(stack, tokens[1], lineno);
		return (1);
	}
	for (i = 0; fun[i].opcode; i++)
	{
		if (strcmp(fun[i].opcode, tokens[0]) == 0)
		{
			fun[i].f(stack, lineno);
			return (1);
		}
	}
	print_error(MONTY_ERROR_UNKNOWN_INSTR, lineno, tokens[0]);
	return (0);
}
