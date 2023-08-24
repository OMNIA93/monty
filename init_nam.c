#include "monty.h"

/**
 * init - ...
 * @name: Arg 1.
 * Return: ...
 */
void init(char *name)
{
	Global.fd = open(name, O_RDONLY);
	if (Global.fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	Global.stack = NULL;
	Global.opcodes = NULL;
	Global.inst = NULL;
	Global.ln = 1;
	Global.type = 1;
	add_new_inst("pall", pall);
	add_new_inst("push", push);
	add_new_inst("pint", pint);
	add_new_inst("nop", nop);
	add_new_inst("pop", pop);
	add_new_inst("swap", swap);
	add_new_inst("add", add);
	add_new_inst("sub", sub);
	add_new_inst("div", divv);
	add_new_inst("mul", mul);
	add_new_inst("mod", mod);
	add_new_inst("pchar", pchar);
	add_new_inst("pstr", pstr);
	add_new_inst("rotl", rotl);
	add_new_inst("rotr", rotr);
	add_new_inst("stack", stack);
	add_new_inst("queue", queue);
}
