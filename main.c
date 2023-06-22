#include "monty.h"

/**
 * main - check code
 * @argc: arguments count
 * @argv: argument vetor
 *
 * Return: EXIT_SUCCESS, or EXIT_FAILURE if it failed
 */
int main(int argc, char *argv[])
{
	args_t args;

	args.av = argv[1];
	args.ac = argc;
	args.line_number = 0;

	monty(&args);

	return (EXIT_SUCCESS);
}
