#include "monty.h"

/**
 * rotr_opcode - rotates the stack to the bottom
 * @stack: pointer to the address of the stack
 * @line_number: line number where the instruction appear in the file
*/
void rotr_opcode(stack_t **stack, unsigned int line_number)
{
stack_t *current_node;
int prev_node_value, j;

UNUSED(line_number);

if (*stack == NULL)
return;

j = (*stack)->n;
current_node = (*stack)->next;
while (current_node)
{
prev_node_value = j;
j = current_node->n;
current_node->n = prev_node_value;
current_node = current_node->next;
}
(*stack)->n = j;
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

if (*stack == NULL)
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
