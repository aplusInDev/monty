#include "monty.h"
#include "lists.h"

/**
 *pchar_handler - Handles the 'pchar' instructio
 *@stack: Double pointer to the stack to retrieve the top element from
 *@line_number: Number of the line in the file
 */
void pchar_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = *stack;
	if (!new_node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (new_node->n < 0 || new_node->n > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	putchar(new_node->n);
	putchar('\n');
}

/**
 *pstr_handler - Handles the 'pstr' instruction
 *@stack: Double pointer to the stack to retrieve elements from
 *@line_number: Number of the line in the file
 */
void pstr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = *stack;
	(void) line_number;
	if (!new_node)
	{
		putchar('\n');
		return;
	}

	while (new_node && new_node->n != 0 && new_node->n >= 0 && new_node->n <= 127)
	{
		putchar(new_node->n);
		new_node = new_node->next;
	}

	putchar('\n');
}
