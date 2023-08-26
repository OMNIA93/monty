#include "monty.h"

/**
 * get_operate - select to perform a specific operation
 * @opcode: the opcode operation to be performed
 * Return: pointer to function to perform the opcode
 *				 or NULL if the opcode is invalid
*/
void (*get_operate(char *opcode))(stack_t **stack, unsigned int line_number)
{
int idx;
instruction_t instructions_arr[] = {
{"push", push_opcode},
{"pall", pall_opcode},
{"pint", pint_opcode},
{"pop", pop_opcode},
{"swap", swap_opcode},
{"add", add_opcode},
{"nop", nop_opcode},
{"sub", sub_opcode},
{"div", div_opcode},
{"mul", mul_opcode},
{"mod", mod_opcode},
{"pchar", pchar_opcode},
{"pstr", pstr_opcode},
{"rotl", rotl_opcode},
{"rotr", rotr_opcode},
{NULL, NULL}
};

for (idx = 0; instructions_arr[idx].opcode; idx++)
{
if (!strcmp(instructions_arr[idx].opcode, opcode))
{
return (instructions_arr[idx].f);
}
}
return (NULL);
}

/**
 * execute_operate - execute the operation of the corresponding opcode
 * @file_name: the file name the contains the opcode
 * Return: EXIT_SUCCESS
*/
int execute_operate(char *file_name)
{
FILE *file = open_file(file_name);
char *line = NULL;
size_t len = 0;
ssize_t chars_read;
unsigned int line_number = 0;

while ((chars_read = getline(&line, &len, file)) != -1)
{
line_number++;
/* Process the line here */
/* Example: parse_line(line, line_number); */
}

free(line);
fclose(file);

return EXIT_SUCCESS;
}	

/**
 * check_mode - checks the mode of stack
 * @tokenized_str: tokenized string
 * Return: 1 for comment or NULL or change mode, 0 if nothing
*/
int check_mode(char **tokenized_str)
{
	if (tokenized_str[0] == NULL || tokenized_str[0][0] == COMMENT)
	{
		free_tokenized_string(execution_env.tokenized_str);
		return (1);
	}

	if (!strcmp(tokenized_str[0], STACK) || !strcmp(tokenized_str[0], QUEUE))
	{
		update_mode(tokenized_str[0]);
		free_tokenized_string(execution_env.tokenized_str);
		return (1);
	}

	return (0);
}
