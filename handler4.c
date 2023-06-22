#include "monty.h"

/**
 * get_func - manage all functions
 * @parsed: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function (success),
 * or NULL (failure)
 */
void (*get_func(char **parsed))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"nop", nop_handler},
		{"sub", sub_handler},
		{"div", div_handler},
		{"mul", mul_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"stack", stack_handler},
		{"queue", queue_handler},
		{NULL, NULL}};
	int i = 0;

	while (func_arr[i].opcode != NULL)
	{
		if (strcmp(func_arr[i].opcode, parsed[0]) == 0)
			return (func_arr[i].f);
		i++;
	}
	return (NULL);
}

/**
 * pchar_handler - Handles the 'pchar' instructio
 * @stack: Double pointer to the stack to retrieve the top element from
 * @line_number: Number of the line in the file
 *
 * Return: nothing
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
 * pstr_handler - Handles the 'pstr' instruction
 * @stack: Double pointer to the stack to retrieve elements from
 * @line_number: Number of the line in the file
 *
 * Return: nothing
 */
void pstr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = *stack;
	(void)line_number;
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
