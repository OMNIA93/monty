#include "monty.h"

/**
 * free_list - frees a doubly linked list.
 * @head: dlinked list head
*/
void free_list(stack_t *head)
{
stack_t *value;

while (head)
{
value = head;
head = head->next;
free(value);
}
}

/**
 * free_tokenized_str - free an array of character pointers to tokenized str
 * @tokenized_str: an array of character pointers to tokenized string
*/
void free_tokenized_str(char **tokenized_str)
{
int idx;

for (idx = 0; tokenized_str[idx]; idx++)
free(tokenized_str[idx]);

free(tokenized_str);
}

/**
 * free_and_exit - free the allocated memories
 *                     and exit the program with EXIT_FAILURE status
 */
void free_and_exit(void)
{
if (execution_env.stack)
free_linked_list(execution_env.stack);

if (execution_env.tokenized_str)
free_tokenized_string(execution_env.tokenized_str);

if (execution_env.line_buffer)
free(execution_env.line_buffer);

if (execution_env.file_pointer)
fclose(execution_env.file_pointer);

exit(EXIT_FAILURE);
}
