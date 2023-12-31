#include "monty.h"

/**
 * swap_error - prints to stderr when stack has less than 2 elements
 * @line_number: line number where the instruction appear in the file
*/
void swap_error(unsigned int line_number)
{
	char *mode;

	if (execution_env.mode == STACK_MODE)
		mode = STACK;
	else
		mode = QUEUE;

	fprintf(stderr, "L%d: can't %s, %s too short\n", line_number,
					execution_env.tokenized_str[0], mode);
	free_and_exit();
}

/**
 * invalid_error - prints to stderr when the opcode is inavlid
 * @line_number: line number where the instruction appear in the file
*/
void invalid_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number,
					execution_env.tokenized_str[0]);
	free_and_exit();
}

