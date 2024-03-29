#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*--- Struct Definitions ---*/
extern int push_arg;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - opcoode and its function
 * @file: the opcode
 * @push_arg: function to handle the opcode
 * @buffer: pointer to
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_variable
{
	FILE *file;
	int push_arg;
	char *buffer;
} global_var;

extern global_var var_global;

void read_files(char *file_name, stack_t **stack);
char *parse_lines(char *line, stack_t **stack, unsigned int line_number);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *str);
int isnumbers(char *strr);

/*Fuxntions Monty*/
void fun_pall(stack_t **stack, unsigned int line_number);
void fun_push(stack_t **stack, unsigned int line_number);
void fun_pint(stack_t **stack, unsigned int line_number);
void fun_pop(stack_t **stack, unsigned int line_number);
void fun_swap(stack_t **stack, unsigned int line_number);
void fun_nop(stack_t **stack, unsigned int line_number);
void fun_rotl(stack_t **stack, unsigned int line_number);
void fun_rotr(stack_t **stack, unsigned int line_number);

/*Functions string ascci */
void fun_pchar(stack_t **stack, unsigned int line_number);
void fun_pstr(stack_t **stack, unsigned int line_number);

/*Functions math*/
void fun_sub(stack_t **stack, unsigned int line_number);
void fun_add(stack_t **stack, unsigned int line_number);
void fun_mul(stack_t **stack, unsigned int line_number);
void fun_div(stack_t **stack, unsigned int line_number);
void fun_mod(stack_t **stack, unsigned int line_number);

/*Utility functions*/
void free_dlistints(stack_t *head);
void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);
int fun_isalpha(int c);
#endif
