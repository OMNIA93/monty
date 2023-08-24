#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 256

/**
 * main - Entry point for Monty Interpreter
 * @argc: number of arguments
 * @argv: array of character pointers to arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
*/
int main(int argc, char *argv[])
{
char line[MAX_LINE_LENGTH];
FILE *file;
stack_t *stack = NULL;
unsigned int counter = 0;

if (argc != 2)
{
printf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
bus.file = file;

if (!file)
{
printf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

while (fgets(line, sizeof(line), file))
{
counter++;
bus.content = line;
execute(line, &stack, counter, file);
}

free_stack(stack);
close(file);

return (0);
}
