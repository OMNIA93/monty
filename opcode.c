#include "monty.h"

/**
 * add_opcode - adds the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 */
void add_opcode(stack_t **stack, unsigned int line_number)
{
	int i;

	if (get_list_length(*stack) < 2)
	{
		two_elements_error(line_number);
	}

	i = (*stack)->n;
	delete_first_node(stack);
	(*stack)->n += i;
}

/**
 * sub_opcode - subtracts the top element of the stack from the second top
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 */
void sub_opcode(stack_t **stack, unsigned int line_number)
{
int i;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

two_elements_error(8, line_number, "sub");


(*stack) = (*stack)->next;
i = (*stack)->n - (*stack)->prev->n;
(*stack)->n = i;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
 * div_opcode - divides the second top element of the stack by the top element
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty script
 */
void div_opcode(stack_t **stack, unsigned int line_number)
{
	int i;

	if (get_list_length(*stack) < 2)
	{
		two_elements_error(line_number);
	}
	if ((*stack)->n == 0)
	{
		division_by_zero(line_number);
	}

	i = (*stack)->n;
	delete_first_node(stack);
	(*stack)->n /= i;
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
		two_elements_error(line_number);
	}

	i = (*stack)->n;
	delete_first_node(stack);
	(*stack)->n *= i;
}

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
		two_elements_error(line_number);
	}

	if ((*stack)->n == 0)
	{
		division_by_zero(line_number);
	}

	i = (*stack)->n;
	delete_first_node(stack);
	(*stack)->n %= i;
}
