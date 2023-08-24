#include "monty.h"

/**
 * main - ...
 * @ac: Arg 1.
 * @av: arg 2.
 * Return: ...
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	init(av[1]);
	exic();
	return (0);
}
