#include "monty.h"

/**
 * monty_parse - parses the input file
 * @fp : The file for which the stack has to be built
 *
 * Return:
 */
void monty_parse(FILE *fp)
{
	char *line;
	ssize_t read;
	size_t len;
	unsigned int lineno;

	lineno = 0;
	len = 0;
	read = 0;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		lineno++;
		strstrip(line); /* strip the empty lines*/
		if (strlen(line) && monty_validate(line, lineno))
			monty_execute(line, lineno);
	}
	free_stack(stack);
	if (line)
		free(line);
}
