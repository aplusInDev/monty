#include "monty.h"
#include "lists.h"

/**
 *rotl_handler - Handle the 'rotl' instruction
 *@stack: Double pointer to the stack
 *@line_number: Line number in the file
 */
void rotl_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;
	int value = 0;

	(void) line_number;

	if (*stack == NULL)
		return;
	current_node = get_dnodeint_at_index(*stack, 0);
	value = current_node->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, value);
}

/**
 *rotr_handler - Handle the 'rotr' instruction
 *@stack: Double pointer to the stack
 *@line_number: Line number in the file
 */
void rotr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;
	int value = 0, length = dlistint_len(*stack);

	(void) line_number;

	if (*stack == NULL)
		return;
	current_node = get_dnodeint_at_index(*stack, length - 1);
	value = current_node->n;
	delete_dnodeint_at_index(stack, length - 1);
	add_dnodeint(stack, value);
}

/**
 *stack_handler - Handle the 'stack' instruction
 *@stack: Double pointer to the stack
 *@line_number: Line number in the file
 */
void stack_handler(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	data.qflag = 0;
}

/**
 *queue_handler - Handle the 'queue' instruction
 *@stack: Double pointer to the stack
 *@line_number: Line number in the file
 */
void queue_handler(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	data.qflag = 1;
}
