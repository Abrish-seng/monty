#include "monty.h"
global_var var_global;
/**
 * main - driver function for monty programs
 * @ac: int num of the arguments
 * @av: opcode files
 * Return: 0
 */
int main(int acc, char **av)
{
	stack_t *stack;
	stack = NULL;
	if (acc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(av[1], &stack);
	free_dlistint(stack);
	return (0);
}
