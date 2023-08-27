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
free_and_exit();
}
delete_first_node(stack);
}
/**
 * add_opcode - adds the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 */
void add_opcode(stack_t **stack, unsigned int line_number)
{
int value1, value2, result;

if (get_list_length(*stack) < 2)
{
swap_error(line_number);
}
value1 = (*stack)->n;
delete_first_node(stack);
value2 = (*stack)->n;
delete_first_node(stack);
result = value1 + value2;
add_node_at_first(stack, result);
}

/**
 * sub_opcode - subtracts the top element of the stack from the second top
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 */
void sub_opcode(stack_t **stack, unsigned int line_number)
{
int value1, value2, result;

if (get_list_length(*stack) < 2)
{
swap_error(line_number);
}

value1 = (*stack)->n;
delete_first_node(stack);
value2 = (*stack)->n;
delete_first_node(stack);

result = value2 - value1;
add_node_at_first(stack, result);
}

/**
 * div_opcode - divides the second top element of the stack by the top element
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 */
void div_opcode(stack_t **stack, unsigned int line_number)
{
int value1, value2, result;
if (get_list_length(*stack) < 2)
{
swap_error(line_number);
}
value1 = (*stack)->n;
delete_first_node(stack);
value2 = (*stack)->n;
delete_first_node(stack);
result = value2 - value1;
add_node_at_first(stack, result);
}

/**
 * mul_opcode - multiplies the second top element of the stack with the top
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 */
void mul_opcode(stack_t **stack, unsigned int line_number)
{
int i;
if (get_list_length(*stack) < 2)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

i = (*stack)->n;
swap_error(line_number);


delete_first_node(stack);

(*stack)->n *= i;
}
