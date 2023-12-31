#include "monty.h"

/**
 * push_opcode - Opcode `push` pushes an element to stack in a Monty script
 * @stack: double pointer to the stack structure stack_t
 *         It represents the address of the top element of the stack
 * @line_number: line number in the Monty script
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
int value;
int number;
char *opcode = execution_env.tokenized_str[0];
char *argument = execution_env.tokenized_str[1];

if (!execution_env.tokenized_str[1])
push_non_integer(line_number, opcode);

for (value = 0; argument[value]; value++)
{
if (!isdigit(argument[value]) && argument[0] != '-')
push_non_integer(line_number, opcode);
}

number = atoi(argument);

if (execution_env.mode == STACK_MODE)
add_node_at_head(stack, number);
else if (execution_env.mode == QUEUE_MODE)
add_node_at_last(stack, number);
}
/**
 * pall_opcode - Opcode `pall` prints all the value of the
 *               stack in a Monty script
 * @stack: head of double pointer to the stack structure stack_t
 *         It represents the address of the top element of the stack
 * @line_number: line number in the Monty script
 */
void pall_opcode(stack_t **stack, unsigned int line_number)
{
UNUSED(line_number);

if (!stack || !*stack)
return;

print_list(*stack);
}
/**
 * pint_opcode - Opcode `pint` prints the top of stack in a Monty script
 * @stack: double pointer to the stack structure stack_t
 *         It represents the address of the top element of the stack
 * @line_number: line number in the Monty script
 */
void pint_opcode(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
empty_error(line_number, execution_env.tokenized_str[0]);
free_and_exit();
}
printf("%d\n", (*stack)->n);
}
