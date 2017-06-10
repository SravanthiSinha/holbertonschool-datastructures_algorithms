#include "monty.h"

static char *opcodes[4] = {"push", "pall", "pint", "pop"};

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
 * Return: On success - 1, on failure 0, on invalid instruction -1
 */
int validate_instruction(char *line, ssize_t len, char **opcode, int lno)
{
	int exit_value;

	exit_value = 1;
	if (strstr(line, opcodes[0]) != NULL)
	{
		/* contains push*/
		*opcode = strdup(opcodes[0]);
		if (!check_element_int(line, len, *opcode))
		{
			printf("L%d: usage: push integer\n", lno);
			exit_value = -1;
		}
	}
	else if (strstr(line, opcodes[1]) != NULL)
	{
		/* contains pall*/
		*opcode = strdup(opcodes[1]);
	}
	else if (strstr(line, opcodes[2]) != NULL)
	{
		/* contains pint*/
		*opcode = strdup(opcodes[2]);
	}
	else if (strstr(line, opcodes[3]) != NULL)
	{
		/* contains pop*/
		*opcode = strdup(opcodes[3]);
	}
	else if (len == 1)
	{
				/* contains blank line*/
		*opcode = NULL;
	}
	else
	{
		exit_value = 0;
	}
	return (exit_value);
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
	int exit_value;


	lineno = 0;
	opcode = NULL;
	read = 0;
	line = 0;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		lineno++;
		exit_value = validate_instruction(line, read, &opcode, lineno);
		if (exit_value  == 0)
		{
			printf("L%d: unknown instruction %s\n", lineno, opcode);
			free(opcode);
			return (0);
		}
		free(opcode);
	}
	if (line)
		free(line);
	rewind(fp);
	return (exit_value);
}
