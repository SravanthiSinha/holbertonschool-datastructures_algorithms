#ifndef _MONTY_H_
#define _MONTY_H_

#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_s.h"
#include "instruction_s.h"
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

int check_element_int(char *line);
char *strstrip(char *s);

int push_stack(stack_t **stack, int n);
void print_stack(stack_t *stack);
void free_stack(stack_t *stack);
void print_stack_top(stack_t **stack, unsigned int lineno);
void pop_stack(stack_t **stack, unsigned int lineno);

typedef void (*funcPtr)(stack_t **stack, unsigned int line_number);
void (*get_op_func(char *c))(stack_t **stack, unsigned int line_number);


void print_error(int errcode, int lineno, char *opcode);
void monty_parse(FILE *fp);
int monty_validate(char *line,  unsigned int lineno);
void monty_execute(char *line, unsigned int lineno);
extern stack_t *stack;
#endif
