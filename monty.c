#include "monty.h"

execution_env_t execution_env = EXECUTION_ENV_INITIALIZER;

/**
 * main - Entry point for Monty Interpreter
 * @argc: number of arguments
 * @argv: array of character pointers to arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
*/
int main(int argc, char *argv[])
{
if (argc != 2)
{
error_1();
}

return (execute_operate(argv[1]));
}
/**
 * open_file - Opens a file and returns a pointer to FILE structure
 * @file_name: Name of the file to open
 * Return: Pointer to the opened file, or NULL on failure
 */
FILE *open_file(char *file_name)
{
FILE *file = fopen(file_name, "r");
if (file == NULL)
{
perror("Error opening file");
exit(EXIT_FAILURE);
}
return (file);
}
