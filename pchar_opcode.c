#include "monty.h"

/**
 * pstr_opcode - prints the string starting at the top of the stack
 * @stack: pointer to the head of stack
 * @line_number: line number in the Monty script
 */
void pstr_opcode(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

UNUSED(line_number);

while (current != NULL && current->n != 0 && isascii(current->n))
{
<<<<<<< HEAD
ascii_out(line_number, execution_env.tokenized_str[0]);
=======
putchar(current->n);
current = current->next;
>>>>>>> 543872e91f9d8f22f65933ca9dc97bc48dcf7539
}

putchar('\n');
}

/**
 * pchar_opcode - prints the char at the top of the stack
 * @stack: pointer to the head of stack
 * @line_number: line number in the Monty script
 */
void pchar_opcode(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
empty_error(line_number, execution_env.tokenized_str[0]);
}

if (!isascii((*stack)->n))
{
ascii_out_of_range(line_number, execution_env.tokenized_str[0]);
}

printf("%c\n", (*stack)->n);
}
