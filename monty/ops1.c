#include "monty.h"

/**
 * pop - pop top element off of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.stack_len != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(pop);
	var.stack_len--;
}

/**
 * add - add the top two elements of the stack
 * @stack: double pointer tot he beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n += (*stack)->n;
	pop(stack, line_number);
	(*stack)->n += n;
}

/**
 * sub - subtract top element of stack from next element and push result
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= n;
}

/**
 * nop - no operation performed
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
