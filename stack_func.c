#include "monty.h"
/**
 * fun_push - push int to a stacks
 * @stack: linked lists for monty stacks
 * @line_number: number of line opcode occurs on stacks
 */
void fun_push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_global.push_arg;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * fun_pall - print all functions
 * @stack: pointer to linked list stacks
 * @line_number: number of line opcode occurs on stacks
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	do
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}while (runner != NULL);
}

/**
 * fun_pint - print int a top of stacks
 * @stack: pointer to linked list stacks
 * @line_number: number of line opcode occurs on stacks
 *
 */
void fun_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * fun_pop - remove element a lists
 *@stack: pointer to first node of the stack
 *@line_number: integers
 *Return: void
 */
void fun_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * free_dlistint - free a lists
 * @head: pointer to first node of the stack
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	do
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}while (head != NULL);
}
