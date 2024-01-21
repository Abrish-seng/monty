#include "monty.h"
/**
 * fun_swap - swap top of stack y second top stacks
 * @stack: pointer to lists for monty stacks
 * @line_number: number of line opcode occurs on the stack
 */

void fun_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (runner == NULL || runner->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}

/**
 * fun_add - add top of stack y second top stacks
 * @stack: pointer to lists for monty stacks
 * @line_number: number of line opcode occurs on the stacks
 */

void fun_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sum = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	fun_pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * fun_nop - nop top of stack y second top stacks
 * @stack: pointer to lists for monty stacks
 * @line_number: number of line opcode occurs on the stack
 */

void fun_nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * fun_pchar - prints the ASCII value of a numbers
 * @stack: pointer to the top of the stacks
 * @line_number: the index of the current lines
 *
 */
void fun_pchar(stack_t **stack, unsigned int line_number)
{
	int val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistints(*stack);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;
	if (val > 127 || val < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistints(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n');
}

/**
 * fun_isalpha - checks if int is in alphabets
 * @c: integer
 * Return: 1 if yes, 0 if no
 */
int fun_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
