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
if (!strcmp(instructions_arr[idx].opcode, opcode))
return (instructions_arr[idx].f);

return (NULL);
}
