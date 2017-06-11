#ifndef _MONTY_H_
#define _MONTY_H_

#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

#define MONTY_NONE 0
#define MONTY_ERROR_UNKNOWN_INSTR 1
#define MONTY_ERROR_MALLOC 2
#define MONTY_ERROR_STACK_SHORT 3
#define MONTY_ERROR_OUT_OF_RANGE 4
#define MONTY_ERROR_INT 5
#define MONTY_ERROR_STACK_EMPTY 6
#define MONTY_ERROR_DIV_BY_ZERO 7

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



int check_element_int(char *line);
char *strstrip(char *s);

int push_stack(stack_t **stack, char *n, int lineno);
void print_stack(stack_t **stack, unsigned int lineno);
void free_stack(stack_t *stack);
void print_stack_top(stack_t **stack, unsigned int lineno);
void pop_stack(stack_t **stack, unsigned int lineno);
void swap_tops(stack_t **stack, unsigned int lineno);
void add(stack_t **stack, unsigned int lineno);
void sub(stack_t **stack, unsigned int lineno);
void divide(stack_t **stack, unsigned int lineno);
void mul(stack_t **stack, unsigned int lineno);
void mod(stack_t **stack, unsigned int lineno);
void pchar(stack_t **stack, unsigned int lineno);
void pstr(stack_t **stack, unsigned int lineno);
void rotl(stack_t **stack, unsigned int lineno);


void print_error(int errcode, int lineno, char *opcode);
int monty_parse(FILE *fp);
int monty_execute(stack_t **stack, char **tokens, unsigned int lineno);
int isnum(char *str);
extern stack_t *stack;
#endif
