#include "monty.h"

/**
 * push_opcode - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The current line number in the file.
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
char *argument = execution_env.tokenized_str[1];

if (!argument || !is_number(argument))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
free_all_and_exit();
}

int number = atoi(argument);

if (execution_env.mode == STACK_MODE)
add_node_at_first(stack, number);
else if (execution_env.mode == QUEUE_MODE)
add_node_at_end(stack, number);
}

/**
 * pall_opcode - Prints all values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The current line number in the file.
 */
void pall_opcode(stack_t **stack, unsigned int line_number)
{
UNUSED(line_number);

print_list(*stack);
}
