#include "monty.h"

/**
	* print_error -  Prints the Error based on the errorcode and exits
	* @errorcode : The errorcode to be analyesed
	* @lineno : the line no of the error occured
	* @opcode: The operation code where the error occured.
	*/

void print_error(int errorcode, int lineno, char *opcode)
{

	if (errorcode == MONTY_ERROR_MALLOC)
		printf("Error: malloc failed\n");
	else if (errorcode == MONTY_ERROR_UNKNOWN_INSTR)
		printf("L%d: unknown instruction %s\n", lineno, opcode);
	else if (errorcode == MONTY_ERROR_STACK_SHORT)
		printf("L%d: can't %s, stack too short\n", lineno, opcode);
	else if (errorcode == MONTY_ERROR_INT)
		printf("L%d: usage: push integer\n", lineno);
	else if (errorcode == MONTY_ERROR_STACK_EMPTY)
		printf("L%d: can't pint, stack empty\n", lineno);
	else if (errorcode == MONTY_ERROR_DIV_BY_ZERO)
		printf("L%d: division by zero\n", lineno);
}
