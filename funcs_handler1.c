#include "monty.h"
#include "lists.h"

/**
 *pint_handler - Handles the pint instruction
 *@stack: Double pointer to the stack to push to
 *@line_number: Number of the line in the file
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
 *pop_handler - Handles the pop instruction
 *@stack: Double pointer to the stack to modify
 *@line_number: Number of the line in the files
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
 *swap_handler - Handles the swap instruction
 *@stack: Double pointer to the stack to modify
 *@line_number: number of the line in the file
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

/**
 *add_handler - Handles the add instruction
 *@stack: Double pointer to the stack to modify
 *@line_number: Number of the line in the file
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
 *nop_handler - Handles the nop instruction
 *@stack: Double pointer to the stack
 *@line_number: Number of the line in the file
 */
void nop_handler(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
