#include "monty.h"

stack_t *stack = NULL;
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
					exit_value = (monty_parse(fp) == 1 ? EXIT_SUCCESS : EXIT_FAILURE);
					fclose(fp);
			}
		}
	return (exit_value);
}
