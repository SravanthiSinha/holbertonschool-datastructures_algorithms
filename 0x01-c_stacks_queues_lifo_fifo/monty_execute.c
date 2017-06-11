#include "monty.h"

/**
 * monty_execute - Executes an instruction set based on the opcode
 * @line : Instruction
 * @lineno : The line no of the instruction set.
 *
 */
void monty_execute(char *line, unsigned int lineno)
{
	char *opcode;
	instruction_t *instruction;

	opcode = strtok(line, " ");
	if (strcmp(opcode, "push") == 0) /* contains push*/
		push_stack(&stack, atoi(strtok(NULL, line)));
	else if (strcmp(opcode, "pall") == 0) /* contains push*/
		print_stack(stack);
	else
	{
		instruction = malloc(sizeof(instruction_t));
		instruction->opcode = strdup(opcode);
		instruction->f = get_op_func(instruction->opcode);
		if (instruction->f != NULL)
			instruction->f(&stack, lineno);
		free(instruction->opcode);
		free(instruction);
	}
}
