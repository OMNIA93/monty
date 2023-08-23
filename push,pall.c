#include "monty.h"

/**
 * push - push element into the stack
 * @stack: stack given by main
 * @line_cnt: ammount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_cnt)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = *stack;
	*stack = new_node;
}
/**
 * pall - prints the stack
 * @stack: stack given by main
 * @line_cnt: ammount of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_cnt)
{
	stack_t *current = *stack;

	while (current != NULL)

	{
	printf("%d\n", current->n);
	current = current->next;
	}
}
