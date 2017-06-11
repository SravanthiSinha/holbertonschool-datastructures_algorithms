#include "monty.h"

/**
 * check_element_int - Takes an instruction set and checks if the operand is
 *                     present
 * @line : Instruction
 *
 * Return: On success - 1, on failure 0
 */
int check_element_int(char *line)
{
	char *dest;
	int pos_of_opcode;
	int pos_of_ele;
	int len;

	len = strlen(line);
	dest = strstr(line, "push");
	pos_of_opcode = dest - line;
	pos_of_ele = pos_of_opcode + strlen("push");
	while (pos_of_ele < len)
	{
		if (line[pos_of_ele] >= 48 && line[pos_of_ele] <= 57)
			return (1);
		else if (line[pos_of_ele] == 32 || line[pos_of_ele] == 9)
			pos_of_ele++;
		else
			return (0);
	}
	return (0);
}

/**
 * monty_validate - Validates an instruction set and checks if the opcodeis
 *                     present
 * @line : Instruction
 * @lineno : The line no of the instruction set.
 *
 * Return: On success - 1, on failure 0
 */
int monty_validate(char *line, unsigned int lineno)
{
	char *opcode;
	int i;
	char *opcodes[4] = {"push", "pall", "pint", "pop"};

	if (strstr(line, opcodes[0]) != NULL)
	{
		if (check_element_int(line))
			return (1);
		print_error(MONTY_ERROR_INT, lineno, "NULL");
	}
	else
	{
		opcode = strtok(line, " ");
		for (i = 1; i < 4; i++)
		{
			if (strcmp(opcode, opcodes[i]) == 0)
				return (1);
		}
	}
	print_error(MONTY_ERROR_UNKNOWN_INSTR, lineno, opcode);
	return (0);
}
