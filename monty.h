#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/* Structures */
/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value of the node
 * @prev: Pointer to the previous element of the stack (or queue)
 * @next: Pointer to the next element of the stack (or queue)
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 */
typedef struct bus_s
{
	char *arg;
	int lifi;
	FILE *file;
	char *content;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void fpush(stack_t **head, unsigned int number);
void fpall(stack_t **head, unsigned int number);
void fpint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void fpop(stack_t **head, unsigned int counter);
void fswap(stack_t **head, unsigned int counter);
void fadd(stack_t **head, unsigned int counter);
void fnop(stack_t **head, unsigned int counter);
void fstack(stack_t **head, unsigned int counter);

void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
#endif
