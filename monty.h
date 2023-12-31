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

char **tokenize_string(const char *delim);
FILE *open_file(char *file_name);
ssize_t read_line(size_t *buffer_size);

void (*get_operate(char *opcode))(stack_t **stack, unsigned int line_number);

int execute_operate(char *file_name);
int check_mode_comment(char **tokenized_str);

void update_mode(char *opcode);

void error_1(void);
void error_2(char *file_name);
void error_3(void);

void swap_error(unsigned int line_number);
void invalid_error(unsigned int line_number);

void ascii_out(unsigned int line_number, char *opcode);
void push_non_integer(unsigned int line_number, char *opcode);
void empty_error(unsigned int line_number, char *opcode);
void div_zero(unsigned int line_number);

stack_t *get_end_node(stack_t **head);
stack_t *add_node_at_last(stack_t **head, int n);
size_t get_length(const stack_t *head);
stack_t *add_node_at_head(stack_t **head, int n);

void print_list(const stack_t *head);
stack_t *delete_first_node(stack_t **head);

void push_opcode(stack_t **stack, unsigned int line_number);
void pall_opcode(stack_t **stack, unsigned int line_number);
void pint_opcode(stack_t **stack, unsigned int line_number);

void mod_opcode(stack_t **stack, unsigned int line_number);
void nop_opcode(stack_t **stack, unsigned int line_number);
void swap_opcode(stack_t **stack, unsigned int line_number);

void pop_opcode(stack_t **stack, unsigned int line_number);
void add_opcode(stack_t **stack, unsigned int line_number);
void sub_opcode(stack_t **stack, unsigned int line_number);
void div_opcode(stack_t **stack, unsigned int line_number);
void mul_opcode(stack_t **stack, unsigned int line_number);

void rotr_opcode(stack_t **stack, unsigned int line_number);
void rotl_opcode(stack_t **stack, unsigned int line_number);

void pstr_opcode(stack_t **stack, unsigned int line_number);
void pchar_opcode(stack_t **stack, unsigned int line_number);

void free_and_exit(void);
void free_list(stack_t *head);
void free_tokenized_string(char **tokenized_str);

#endif
