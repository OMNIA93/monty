#include "monty.h"

/**
 * swap_opcode - swaps the top two elements of the stack
 * @stack: pointer to the address of the stack
 * @line_number: line number where the instruction appear in the file
*/
void swap_opcode(stack_t **stack, unsigned int line_number)
{
	int h;

	if (get_list_length(*stack) < 2)
	{
		two_elements_error(line_number);
	}

	h = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = h;
}

/**
 * rotl_opcode - rotates the stack to the top
 * @stack: pointer to the address of the stack
 * @line_number: line number where the instruction appear in the file
*/
void rotl_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;
	int top_value;

	UNUSED(line_number);

	if (!stack || !*stack)
		return;

	top_value = (*stack)->n;
	current_node = *stack;
	while (current_node->next)
	{
		current_node->n = current_node->next->n;
		current_node = current_node->next;
	}
	current_node->n = top_value;
}

/**
 * rotr_opcode - rotates the stack to the bottom
 * @stack: pointer to the address of the stack
 * @line_number: line number where the instruction appear in the file
*/
void rotr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;
	int prev_node_value, h;

	UNUSED(line_number);

	if (!stack || !*stack)
		return;

	h = (*stack)->n;
	current_node = (*stack)->next;
	while (current_node)
	{
		prev_node_value = h;
		h = current_node->n;
		current_node->n = prev_node_value;
		current_node = current_node->next;
	}
	(*stack)->n = h;
}