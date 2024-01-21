#include "monty.h"
/**
 * read_file - reads a bytecode file and runs commands of the file
 * @filename: pathname to files
 * @stack: pointer to the top of the stacks
 */
void read_file(char *file_name, stack_t **stack)
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

	do
	{
		line = parse_line(var_global.buffer, stack, line_count);
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
	}while ((read = getline(&var_global.buffer, &i, var_global.file)) != -1);
	free(var_global.buffer);
	check = fclose(var_global.file);
	if (check == -1)
		exit(-1);
}

/**
 * get_op_func -  checks opcode and returns the correct functions
 * @str: the opcode of the
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
	do
	{
		i++;
	}while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0);

	return (instruct[i].f);
}

/**
 * isnumber - checks if a string is a numbers
 * @str: string being passed to display
 * Return: returns 1 if string is a number, 0 otherwise or not
 */
int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	do
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}while (str[i]);
	return (1);
}

/**
 * parse_line - parses a line for an opcode and argumentes
 * @line: the line to be parsed to
 * @stack: pointer to the head of the stacks
 * @line_number: the current line numbers
 * Return: returns the opcode or null on failures
 */
char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *op_code, *push, *arg;
	(void)stack;

	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			var_global.push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
