#include "monty.h"


static char *opcodes[3] = {"push", "pall", "pint"};

/**
 * execute - Handles the crud operations on stack
 * @fp : The file for which the stack has to be built
 *
 * Return: Nothing
 */
int execute(FILE *fp)
{
	stack_t *stack;
	char *line;
	size_t len;
	ssize_t read;
	int lineno;
	int exit_value;

	exit_value = 1;
	lineno	= 0;
	stack = NULL;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (strstr(line, opcodes[0]) != NULL)/* contains push*/
			exit_value = push(&stack, get_element_int(line, read, opcodes[0]));
		if (strstr(line, opcodes[1]) != NULL)/* contains pall*/
			print_stack(stack);
		if (strstr(line, opcodes[2]) != NULL)/* contains pint*/
			exit_value =	print_stack_top(stack, lineno);
		lineno++;
	}
	free_stack(stack);
	if (line)
		free(line);
	return (exit_value);
}

/**
 * main - Starts the program
 * @argc : no of command line arguments
 * @argv : command line arguments
 *
 * Return: on success - EXIT_SUCCESS, on failure - EXIT_FAILURE
 */
int main(int argc, __attribute__((unused)) char **argv)
{
	FILE *fp;
	int exit_value;

	exit_value = EXIT_FAILURE;
	if (argc != 2)
		printf("USAGE: monty file\n");
	else
	{
		fp = fopen(argv[1], "rt");
		if (fp == NULL)
			printf("Error: Can't open file %s\n", basename(argv[1]));
		else
		{
			if (validate(fp))
			{
				exit_value = execute(fp);
				fclose(fp);
				return (exit_value == 0 ? EXIT_FAILURE : EXIT_SUCCESS);
			}
			fclose(fp);
		}
	}
	return (exit_value);
}
