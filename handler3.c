#include "monty.h"

/**
 * mod_handler - Handle the modulo instruction
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: nothing
 */
void mod_handler(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *new_node = NULL;
	stack_t *new_node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *new_node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MOD_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (new_node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	result = new_node_1->n % new_node_0->n;
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
 * stack_handler - Handle the 'stack' instruction
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: nothing
 */
void stack_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 0;
}

/**
 * rotl_handler - Handle the 'rotl' instruction
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: nothing
 */
void rotl_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;
	int value = 0;

	(void)line_number;

	if (*stack == NULL)
		return;
	current_node = get_dnodeint_at_index(*stack, 0);
	value = current_node->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, value);
}

/**
 * queue_handler - Handle the 'queue' instruction
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: nothing
 */
void queue_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 1;
}

/**
 * rotr_handler - Handle the 'rotr' instruction
 * @stack: Double pointer to the stack
 * @line_number: Line number in the file
 *
 * Return: nothing
 */
void rotr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;
	int value = 0, length = dlistint_len(*stack);

	(void)line_number;

	if (*stack == NULL)
		return;
	current_node = get_dnodeint_at_index(*stack, length - 1);
	value = current_node->n;
	delete_dnodeint_at_index(stack, length - 1);
	add_dnodeint(stack, value);
}
