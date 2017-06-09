#include "monty.h"


static char *opcodes[2] = {"push", "pall"};

/**
 * execute - Handles the crud operations on stack
 * @fp : The file for which the stack has to be built
 *
 * Return: Nothing
 */
void execute(FILE *fp)
{
	stack_t *stack;
	char *line;
	size_t len;
	ssize_t read;

	stack = NULL;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (strstr(line, opcodes[0]) != NULL)
			/* contains push*/
			push(&stack, get_element_int(line, read, opcodes[0]));

		if (strstr(line, opcodes[1]) != NULL)
			/* contains pall*/
			print_stack(stack);
	}
	free_stack(stack);
	if (line)
		free(line);
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
				execute(fp);
				fclose(fp);
				return (EXIT_SUCCESS);
			}
			fclose(fp);
		}
	}
	exit(EXIT_FAILURE);
}
