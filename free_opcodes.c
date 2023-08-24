#include "monty.h"


/**
 * free_inst - function that frees a stack_t list.
 * @str: Arg 1.
 */
void free_inst(char **str)
{
	int i = 0;

	while (str[i])
		free(str[i++]);
	free(str);
}

/**
 * free_stack - function that frees a stack_t list.
 * @head: Arg 1.
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * free_opcodes - function that frees a stack_t list.
 * @head: Arg 1.
 */
void free_opcodes(listOfinst_t *head)
{
	listOfinst_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->inst->opcode);
		free(tmp->inst);
		free(tmp);
	}
}
/**
 * free_all - ...
 */
void free_all(void)
{
	free_stack(Global.stack);
	free_opcodes(Global.opcodes);
	free(Global.left);
	close(Global.fd);
}

/**
 * mexit - ...
 */
void mexit(void)
{
	free(Global.line);
	free_inst(Global.inst);
	free_all();
	exit(EXIT_FAILURE);
}
