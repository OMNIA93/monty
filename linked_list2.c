#include "monty.h"

/**
 * print_list - prints all the elements of a list
 * @first: first of the list
 * Return: the number of nodes
 */
void print_list(const stack_t *first)
{
	const stack_t *current;

	if (!first)
		return;

	current = first;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * delete_first_node - delete the first node
 * @first: pointer to the first of stack
 * Return: address of new head or NULL if empty
 */
stack_t *delete_first_node(stack_t **first)
{
	stack_t *temp = *first;

	if (*first == NULL)
		return (NULL);

	*first = (*first)->next;
	if (*first != NULL)
		(*first)->prev = NULL;

	temp->next = NULL;
	free(temp);

	return (*first);
}
