#include "monty.h"

/**
 * is_num - ...
 * @str: Arg 1.
 * Return: ...
 */
int is_num(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * stack - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	Global.type = 1;
}

/**
 * queue - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	Global.type = 0;
}


/**
 * push - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (!is_num(Global.inst[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		mexit();
	}
	if (Global.type)
		add_node_stack(stack, _atoi(Global.inst[1]));
	else
		add_dnodeint_end(stack, _atoi(Global.inst[1]));
}

/**
 * pall - ...
 * @stack: Arg 1.
 * @line_number: arg 2.
 * Return: ...
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void)line_number;
	while (head)
	{
		fprintf(stdout, "%d\n", head->n);
		head = head->next;
	}
}
