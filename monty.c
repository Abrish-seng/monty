#include "monty.h"
global_var var_global;
/**
 * main - driver function for monty program
 * @ac: int num of arguments
 * @avg: opcode file
 * Return: 0
 */
int main(int ac, char **avg)
{
	stack_t *stack;
	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(avg[1], &stack);
	free_dlistint(stack);
	return (0);
}
