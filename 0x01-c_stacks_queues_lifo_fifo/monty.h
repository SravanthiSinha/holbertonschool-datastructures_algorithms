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

int validate(FILE *fp);
int validate_instruction(char *line, ssize_t read, char **opcode, int lineno);
int check_element_int(char *line, int len, char *opcode);
int get_element_int(char *line, int len, char *opcode);
int push_stack(stack_t **stack, int n);
void print_stack(stack_t *stack);
void free_stack(stack_t *stack);
void print_stack_top(stack_t **stack, unsigned int lineno);
void pop_stack(stack_t **stack, unsigned int lineno);
typedef void (*funcPtr)(stack_t **stack, unsigned int line_number);

void (*get_op_func(char *c))(stack_t **stack, unsigned int line_number);
char *strstrip(char *s);
#endif
