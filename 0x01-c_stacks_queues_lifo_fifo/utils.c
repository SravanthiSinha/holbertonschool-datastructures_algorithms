#include "monty.h"

/**
 * get_element_int - Takes an instruction set and fethces the operand
 * @line : Instruction
 * @len : Length of the Instruction
 * @opcode : The operation code
 *
 * Return: On success - operand, on failure 0
 */
int get_element_int(char *line, int len, char *opcode)
{
	char *dest;
	int pos_of_opcode;
	int pos_of_ele;

	dest = strstr(line, opcode);
	pos_of_opcode = dest - line;
	pos_of_ele = pos_of_opcode + strlen(opcode) - 1;
	while (pos_of_ele < len)
	{
		if (line[pos_of_ele] >= 48 && line[pos_of_ele] <= 57)
			return (atoi(line + pos_of_ele));
		pos_of_ele++;
	}
	return (0);
}
