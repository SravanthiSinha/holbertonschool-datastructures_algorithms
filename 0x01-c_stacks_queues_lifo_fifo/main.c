#include "monty.h"

static char *opcodes[4] = {"push", "pall", "pint", "pop"};

/**
 * execute - Handles the crud operations on stack
 * @fp : The file for which the stack has to be built
 *
 * Return: Nothing
 */
int execute(FILE *fp)
{
	stack_t *stack;
	instruction_t *instruction;
	char *line, *token;
	ssize_t read;
	size_t len;
	unsigned int lineno;
	int exit_value;

	exit_value = 1;
	lineno = 0, len = 0, read = 0;
	stack = NULL;
	instruction = NULL;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		strstrip(line);
		if (strlen(line))
		{
			token = strtok(strstrip(line), " ");
			if (strcmp(token, opcodes[0]) == 0) /* contains push*/
				exit_value = push_stack(&stack, atoi(strtok(NULL, line)));
			else if (strcmp(token, opcodes[1]) == 0) /* contains pall*/
				print_stack(stack);
			else
			{
				instruction = malloc(sizeof(instruction_t));
				instruction->opcode = strdup(token);
				instruction->f = get_op_func(instruction->opcode);
				if (instruction->f != NULL)
					instruction->f(&stack, lineno);
				free(instruction->opcode);
			}
		}
		if (exit_value == 0)
			return (exit_value);
		lineno++;
	}
	free_stack(stack);
	if (line)
		free(line);
	return (1);
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
				printf("Error: Can't open file %s\n", argv[1]);
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
