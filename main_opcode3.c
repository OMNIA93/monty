#include "monty.h"

/**
 * swap_opcode - swaps the top two elements of the stack
 * @stack: pointer to the address of the stack
 * @line_number: line number where the instruction appear in the file
*/
void swap_opcode(stack_t **stack, unsigned int line_number)
{
int j;

if (get_list_length(*stack) < 2)
{
two_elements_error(line_number);
}

j = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = j;
}

