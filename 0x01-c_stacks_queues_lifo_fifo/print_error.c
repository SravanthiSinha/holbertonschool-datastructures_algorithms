#include "monty.h"

/**
	* print_error -  Prints the Error based on the errorcode and exits
	* @errorcode : The errorcode to be analyesed
	* @lineno : the line no of the error occured
	* @opcode: The operation code where the error occured.
	*/

void print_error(int errorcode, int lineno, char *opcode)
{
	int i;
	char *error_msg[3] = {"usage: push integer", "can't pint, stack empty",
			      "division by zero"};

	if (errorcode == MONTY_ERROR_MALLOC)
		printf("Error: malloc failed\n");
	else if (errorcode == MONTY_ERROR_UNKNOWN_INSTR)
		printf("L%d: unknown instruction %s\n", lineno, opcode);
	else if (errorcode == MONTY_ERROR_STACK_SHORT)
		printf("L%d: can't %s, stack too short\n", lineno, opcode);
	else
	{
		for (i = 5; i < 8; i++)
		{
			if (i == errorcode)
			{
				printf("L%d: %s\n", lineno, error_msg[i - 5]);
				break;
			}
		}
	}
	exit(EXIT_FAILURE);
}
