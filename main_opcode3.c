#include "monty.h"
/**
 * mod_opcode - computes the rest of the division of the second top element
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 */
void mod_opcode(stack_t **stack, unsigned int line_number)
{
int i;
if (get_list_length(*stack) < 2)
{
swap_error(line_number);
}
if ((*stack)->n == 0)
{
div_zero(line_number);
}
i = (*stack)->n;
delete_first_node(stack);
(*stack)->n %= i;
}

/**
 * nop_opcode - Opcode `nop` do nothing
 * @stack: double pointer to the stack structure stack_t
 *         It represents the address of the top element of the stack
 * @line_number: line number in the Monty script
 */
void nop_opcode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

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
swap_error(line_number);
}

j = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = j;
}

