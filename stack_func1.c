#include "monty.h"
/**
 * fun_swap - swap top of stack y second top stacks
 * @stack: pointer to lists for monty stacks
 * @line_number: number of line opcode occurs on stacks
 */

void fun_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer;
	int temp;

	pointer = *stack;
	if (pointer == 0 || pointer->next == 0)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = pointer->n;
	pointer->n = pointer->next->n;
	pointer->next->n = temp;
}

/**
 * fun_add - add top of stack y second top stacks
 * @stack: pointer to lists for monty stacks
 * @line_number: number of line opcode occurs on stacks
 */

void fun_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum = 0, i = 0;

	if (temp == 0)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	do
	{
		temp = temp->next;
		i++;
	}while (temp);

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * fun_nop - nop top of stack y second top stacks
 * @stack: pointer to lists for monty stacks
 * @line_number: number of line opcode occurs on stacks
 */

void fun_nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * fun_pchar - prints the ASCII value of a numbers
 * @stack: pointer to the top of the stacks
 * @line_number: the index of the current line number
 *
 */
void fun_pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	if (value > 127 || value < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}

/**
 * fun_isalpha - checks if int is in alphabet
 * @c: int num
 * Return: 1 if yes, 0 if no
 */
int fun_isalpha(int num)
{
	if ((num >= 97 && num <= 122) || (num >= 65 && num <= 90))
		return (1);
	else
		return (0);
}
