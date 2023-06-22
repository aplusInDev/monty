#include "monty.h"

/**
 * push_handler - handles the push instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void push_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new_s;
	int num = 0, i;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	for (i = 0; data.words[1][i]; i++)
	{
		if (isalpha(data.words[1][i]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			free_all(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);
	if (data.qflag == 0)
		new_s = add_dnodeint(stack, num);
	else if (data.qflag == 1)
		new_s = add_dnodeint_end(stack, num);
	if (!new_s)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_handler - handles the pall instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pall_handler(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_dlistint(*stack);
}

/**
 * pint_handler - Handles the pint instruction
 * @stack: Double pointer to the stack to push to
 * @line_number: Number of the line in the file
 *
 * Return: nothing
 */
void pint_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", current->n);
}

/**
 * pop_handler - Handles the pop instruction
 * @stack: Double pointer to the stack to modify
 * @line_number: Number of the line in the files
 *
 * Return: nothing
 */
void pop_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}

/**
 * swap_handler - Handles the swap instruction
 * @stack: Double pointer to the stack to modify
 * @line_number: number of the line in the file
 *
 * Return: nothing
 */
void swap_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *new_node = NULL;
	int number;

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	tmp = get_dnodeint_at_index(*stack, 0);
	number = tmp->n;
	delete_dnodeint_at_index(stack, 0);
	new_node = insert_dnodeint_at_index(stack, 1, number);
	if (!new_node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
