#include "monty.h"

static char *opcodes[2] = {"push", "pall"};

/**
 * check_element_int - Takes an instruction set and checks if the operand is
 *                     present
 * @line : Instruction
 * @len : Length of the Instruction
 * @opcode : The operation code
 *
 * Return: On success - 1, on failure 0
 */
int check_element_int(char *line, int len, char *opcode)
{
	char *dest;
	int pos_of_opcode;
	int pos_of_ele;

	dest = strstr(line, opcode);
	pos_of_opcode = dest - line;
	pos_of_ele = pos_of_opcode + strlen(opcode);
	while (pos_of_ele < len)
	{
		if (line[pos_of_ele] >= 48 && line[pos_of_ele] <= 57)
			return (1);
		else if (line[pos_of_ele] != 32 && line[pos_of_ele] != 9)
			return (0);
		pos_of_ele++;
	}
	return (0);
}


/**
 * validate_instruction - Takes an instruction set and validates it
 * @line : Instruction
 * @len : Length of the Instruction
 * @opcode : The operation code
 * @lno : The line no of the instruction
 *
 * Return: On success - 1, on failure 0
 */
int validate_instruction(char *line, ssize_t len, char *opcode, int lno)
{

	if (strstr(line, opcodes[0]) != NULL)
	{
		/* contains push*/
		opcode = strdup(opcodes[0]);
		if (check_element_int(line, len, opcode))
			return (1);
		printf("L%d: usage: push integer\n", lno);
		exit(EXIT_FAILURE);
	}
	else if (strstr(line, opcodes[1]) != NULL)
	{
		/* contains pall*/
		opcode = strdup(opcodes[1]);
		return (1);
	}
	else if (len == 1)
	{
		/* contains blank line*/
		opcode = NULL;
		return (1);
	}
	return (0);
}


/**
 * validate - The input file to be validated
 * @fp : The input file
 *
 * Return: On success - 1, on failure 0
 */
int validate(FILE *fp)
{
	char *line;
	size_t len;
	ssize_t read;
	int lineno;
	char *opcode;

	lineno = 0;
	line = NULL;
	opcode = NULL;
	len = 0;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		lineno++;
		if (!validate_instruction(line, read, opcode, lineno))
		{
			printf("L%d: unknown instruction %s\n", lineno, opcode);
			return (0);
		}
	}
	rewind(fp);
	if (line)
		free(line);
	return (1);
}
