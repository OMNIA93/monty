#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define UNUSED(x) (void)(x)
#define SPACE " "
#define MAX_TOKENIZED_SIZE 3
#define COMMENT '#'
#define EXECUTION_ENV_INITIALIZER { NULL, NULL, NULL, NULL, 0 }
#define STACK "stack"
#define QUEUE "queue"

/**
 * enum Mode - defines the mode of operation for linked list
 *
 * @STACK_MODE: the linked list operates as a stack
 * @QUEUE_MODE: the linked list operates as a queue
 */
enum Mode
{
	STACK_MODE = 0,
	QUEUE_MODE = 1
};

/**
 * struct stack_s - doubly linked list re-presentation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack or (queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct execution_env - struct to use a group of variables globally
 * @stack: doubly linked list re-presentation of a stack (or queue)
 * @tokenized_str: array of character pointers to the tokenized strings
 * @line_buffer: pointer to buffer that stores opcode
 * @file_pointer: file pointer
 * @mode: stack or queue
*/
typedef struct execution_env
{
	stack_t *stack;
	char **tokenized_str, *line_buffer;
	FILE *file_pointer;
	int mode;
} execution_env_t;

extern execution_env_t execution_env;

void push_opcode(stack_t **stack, unsigned int line_number);
void pall_opcode(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
