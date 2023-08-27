#include "monty.h"
/**
 * pop_opcode - Opcode `pop` removes the top of stack in a Monty script
 * @stack: double pointer to the stack structure stack_t
 *         It represents the address of the top element of the stack
 * @line_number: line number in the Monty script
 */
void pop_opcode(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
empty_stack_error(line_number, execution_env.tokenized_str[0]);
free_all_and_exit();
}
delete_first_node(stack);
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
two_elements_error(line_number);
}

j = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = j;
}

