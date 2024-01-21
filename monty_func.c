#include "monty.h"
/**
 * read_files - reads a bytecode file and runs the commands
 * @file_name: pathname to files
 * @stack: pointer to the top of the stacks
 */
void read_files(char *file_name, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func s;
	int check;
	int read;


	var_global.file = fopen(file_name, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&var_global.buffer, &i, var_global.file)) != -1)
	{
		line = parse_lines(var_global.buffer, stack, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		s(stack, line_count);
		line_count++;
	}
	free(var_global.buffer);
	check = fclose(var_global.file);
	if (check == -1)
		exit(-1);
}

/**
 * get_op_func -  checks opcode and returns the correct functions
 * @str: the opcode of the stacks
 * Return: returns a functions, or NULL on failures
 */
instruct_func get_op_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", fun_push},
		{"pall", fun_pall},
		{"pint", fun_pint},
		{"pop", fun_pop},
		{"swap", fun_swap},
		{"add", fun_add},
		{"nop", fun_nop},
		{"sub", fun_sub},
		{"mul", fun_mul},
		{"div", fun_div},
		{"mod", fun_mod},
		{"pchar", fun_pchar},
		{"pstr", fun_pstr},
		{"rotl", fun_rotl},
		{"rotr", fun_rotr},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

/**
 * isnumbers - checks if a string is a numbers 
 * @str: string being passed to the stack
 * Return: returns 1 if string is a number, 0 otherwise not
 */
int isnumbers(char *strr)
{
	unsigned int i;

	if (strr == NULL)
		return (0);
	i = 0;
	while (strr[i])
	{
		if (strr[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(strr[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * parse_lines - parses a line for an opcode and arguments in the stack
 * @line: the line to be parsed to the stack
 * @stack: pointer to the head of the stacks
 * @line_number: the current line numbers
 * Return: returns the opcode or null on failures
 */
char *parse_lines(char *line, stack_t **stack, unsigned int line_number)
{
	char *op_code, *push, *args;
	(void)stack;

	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		args = strtok(NULL, "\n ");
		if (isnumbers(args) == 1 && args != NULL)
		{
			var_global.push_arg = atoi(args);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
