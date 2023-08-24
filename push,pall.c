#include "monty.h"

/**
 * push - Opcode push pushes an element to the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty script
 */
void push(stack_t **stack, unsigned int line_number)
{
char *arg = bus.arg;
if (!arg || !isdigit(*arg) && *arg != '-')
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free_all_and_exit(EXIT_FAILURE);
}

add_to_stack(stack, atoi(arg));
}
/**
 * pall - Opcode pall prints all values on the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty script
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

UNUSED(line_number);
while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}
