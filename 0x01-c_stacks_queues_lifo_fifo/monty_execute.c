#include "monty.h"

/**
 * monty_execute - Executes an instruction set based on the opcode
 * @tokens : opcode and operand
 * @lineno : The line no of the instruction set.
 *
 * Return: On success - operand, on failure 0
 */
int monty_execute(char **tokens, unsigned int lineno)
{
	instruction_t *instruction;
	int exit_value;

	exit_value = 0;
	if (strcmp(tokens[0], "push") == 0) /* contains push*/
	{
		if (isnum(tokens[1]))
		{
			push_stack(&stack, atoi(tokens[1]));
			return (1);
		}
		else
		{
			print_error(MONTY_ERROR_INT, lineno, NULL);
			return (0);
		}
	}
	else
	{
		instruction = malloc(sizeof(instruction_t));
		instruction->opcode = strdup(tokens[0]);
		instruction->f = get_op_func(instruction->opcode);
		if (instruction->f != NULL)
		{
			instruction->f(&stack, lineno);
			exit_value = 1;
		}
		free(instruction->opcode);
		free(instruction);
	}
	if (exit_value == 0)
	{
	print_error(MONTY_ERROR_UNKNOWN_INSTR, lineno, tokens[0]);
	}
	return (exit_value);
}
