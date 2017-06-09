#ifndef _MONTY_H_
#define _MONTY_H_

#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_s.h"
#include "instruction_s.h"
#include <malloc.h>


int validate(FILE *fp);
int validate_instruction(char *line, ssize_t read, char *opcode, int lineno);
int check_element_int(char *line, int len, char *opcode);
int get_element_int(char *line, int len, char *opcode);
int push(stack_t **stack, int n);
void print_stack(stack_t *stack);
void free_stack(stack_t *stack);
#endif
