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
		{ "pint", &print_stack_top},
		{ "pop", &pop_stack },
		{ NULL, NULL }
	};
	int exit_value;
	int i;

	exit_value = 0;
	if (strcmp(tokens[0], "push") == 0) /* contains push*/
	{
		if (isnum(tokens[1]))
		{
			push_stack(stack, atoi(tokens[1]));
			return (1);
		}
		else
		{
			print_error(MONTY_ERROR_INT, lineno, NULL);
			return (0);
		}
	}

	for (i = 0; fun[i].opcode; i++)
	{
		if (strcmp(fun[i].opcode, tokens[0]) == 0)
		{
			fun[i].f(stack, lineno);
			exit_value = 1;
		}
	}

	if (exit_value == 0)
	print_error(MONTY_ERROR_UNKNOWN_INSTR, lineno, tokens[0]);

	return (exit_value);
}