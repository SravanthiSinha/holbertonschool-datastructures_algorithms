#include "monty.h"

int flag = 0;
/**
 * parse - checks line from file for a single command and argument.
 * @line: A line from file.
 * @tokens: Array of strings.
 *
 * Return: Void.
 */
void parse(char *line, char **tokens)
{
	int i;
	char *token;

	token = strtok(line, " \t\r\n\v\f");
	for (i = 0; token && i < 2; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\r\n\v\f");
	}
	tokens[i] = NULL;
}
/**
 * monty_parse - parses the input file
 * @fp : The file for which the stack has to be built
 *
 * Return: On success - operand, on failure 0
 */
int monty_parse(FILE *fp)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int lineno = 0;
	char *tokens[3] = {NULL, NULL, NULL};
	int exit_value = 1;
	stack_t *stack = NULL;

	while ((getline(&line, &len, fp) != -1) && exit_value)
	{
		lineno++;
		strstrip(line); /* strip the empty lines*/
		if (strlen(line))
		{
			parse(line, tokens);
			if (tokens[0] && tokens[0][0] == '#')
				lineno++;
			else
				{
				exit_value = monty_execute(&stack, tokens, lineno);
			}
		}
	}
	free_stack(stack);
	if (line)
		free(line);
	return (exit_value);
}
