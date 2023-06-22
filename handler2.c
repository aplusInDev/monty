#include "monty.h"

/**
 * add_handler - Handles the add instruction
 * @stack: Double pointer to the stack to modify
 * @line_number: Number of the line in the file
 *
 * Return: nothing
 */
void add_handler(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *new_node = NULL;
	stack_t *new_node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *new_node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	sum = new_node_0->n + new_node_1->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	new_node = add_dnodeint(stack, sum);
	if (!new_node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop_handler - Handles the nop instruction
 * @stack: Double pointer to the stack
 * @line_number: Number of the line in the file
 *
 * Return: nothing
 */
void nop_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub_handler - Handles the sub instruction
 * @stack: Double pointer to the stack
 * @line_number: Number of the line in the file
 *
 * Return: nothing
 */

void sub_handler(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *new_node = NULL;
	stack_t *new_node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *new_node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SUB_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	result = new_node_1->n - new_node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	new_node = add_dnodeint(stack, result);
	if (!new_node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_handler - Handles the div instruction
 * @stack: Double pointer to the stack
 * @line_number: Number of the line in the file
 *
 * Return: nothing
 */
void div_handler(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *new_node = NULL;
	stack_t *new_node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *new_node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, DIV_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (new_node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	result = new_node_1->n / new_node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	new_node = add_dnodeint(stack, result);
	if (!new_node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul_handler -  handle the multiplication instruction
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: nothing
 */
void mul_handler(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *new_node = NULL;
	stack_t *new_node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *new_node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	result = new_node_1->n * new_node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	new_node = add_dnodeint(stack, result);
	if (!new_node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
