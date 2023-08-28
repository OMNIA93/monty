#include "monty.h"

/**
 * ascii_out - print error message when ascii out of range
 * @line_number: line number in the Monty script
 * @opcode: opcode in the Monty script
 */
void ascii_out(unsigned int line_number, char *opcode)
{
	fprintf(stderr, "L%u: can't %s, value out of range\n", line_number, opcode);
	free_and_exit();
}

/**
 * push_non_integer - print error message when pushes non integer value
 * @line_number: line number in the Monty script
 * @opcode: opcode in the Monty script
 */
void push_non_integer(unsigned int line_number, char *opcode)
{
	fprintf(stderr, "L%d: usage: %s integer\n", line_number, opcode);
	free_and_exit();
}

/**
 * empty_error - print error message when stack is empty
 * @line_number: line number in the Monty script
 * @opcode: opcode in the Monty script
 */
void empty_error(unsigned int line_number, char *opcode)
{
	char *mode;

	if (execution_env.mode == STACK_MODE)
		mode = STACK;
	else
		mode = QUEUE;

	if (!strcmp(opcode, "pint") || !strcmp(opcode, "pchar"))
		fprintf(stderr, "L%u: can't %s, %s empty\n", line_number, opcode, mode);
	else if (strcmp(opcode, "pop") == 0)
		fprintf(stderr, "L%u: can't %s an empty %s\n", line_number, opcode, mode);
	free_and_exit();
}

/**
 * div_zero - print error message when division by zero
 * @line_number: line number in the Monty script
 */
void div_zero(unsigned int line_number)
{
	fprintf(stderr, "L%u: divison by zero\n", line_number);
	free_and_exit();
}
