#include "monty.h"

/**
 * fun_pstr - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stacks
 * @line_number: number of line opcode occurs on on stacks
 */
void fun_pstr(stack_t **stack, unsigned int line_counter)
{
	stack_t *temp = *stack;
	int a = 0;

	(void)line_counter;


	do
	{
		a = temp->n;
		if (a == 0 || _isalpha(a) == 0)
			break;
		putchar(a);
		temp = temp->next;
	}while (temp);
	putchar('\n');
}

/**
 * fun_rotl - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stacks
 * @line_number: number of line opcode occurs on the stack
 */
void fun_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;


	int aux = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	aux = runner->n;

	do
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}while (runner->next);

	runner->n = aux;
}

/**
 * fun_rotr - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stacks
 * @line_number: number of line opcode occurs on stacks
 */
void fun_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	int aux = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
		runner = runner->next;

	aux = runner->n;

	do
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}while (runner->prev);

	runner->n = aux;
}
