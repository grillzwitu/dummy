#include "monty.h"

/**
 * check_for_digit - checks that a string only contains digits
 * @arg: string to check
 *
 * Return: 0 if only digits, else 1
 */

static int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * push - push an integer onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_for_digit(arg))
	{
		dprintf(STDOUT_FILENO,
			"L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}

/**
 * pall - print all values on `stack' starting from the top
 * @stack: double pointer to head of stack
 * @line_number: line number being executed from script file
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}
}

/**
 * pint - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
