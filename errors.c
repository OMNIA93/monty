#include "monty.h"

/**
 * error_1 - prints to stderr usage error msg
*/
void error_1(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	free_and_exit();
}

/**
 * error_2 - prints to stderr open error msg
 * @file_name: the opcode file name
*/
void error_2(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	free_and_exit();
}

/**
 * error_3 - prints to stderr malloc error msg
*/
void error_3(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_and_exit();
}
