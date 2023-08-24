#ifndef MONTY_HPP
# define MONTY_HPP
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

# define BUFFER_SIZE 1000
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * struct listOfinst_s - list of listOfinst_t
 * @inst: elm 1.
 * @next: elm 2.
 * Description: Global variable
 */
typedef struct listOfinst_s
{
	instruction_t *inst;
	struct listOfinst_s *next;
} listOfinst_t;

/**
 * struct global_s - opcode and its function
 * @stack: elm 1.
 * @inst: elm 2.
 * @left: elm 3.
 * @ln: elm 4.
 * @fd: elm 5.
 * @opcodes: elm 6.
 * @line: elm 7.
 * @type: elm 8.
 * Description: Global variable
 */
typedef struct global_s
{
	int type;
	char *left;
	int ln;
	stack_t *stack;
	char    **inst;
	int     fd;
	listOfinst_t *opcodes;
	char    *line;
} global_t;
extern global_t Global;

stack_t *add_node_stack(stack_t **head, const int n);
listOfinst_t	*add_node_inst(listOfinst_t **head, instruction_t *inst);
char	*get_next_line(int fd);
size_t	my_strlen(const char *s);
char	*my_strjoin(char *s1, char *s2);
char	*my_strchr(const char *s, int c);
void	*my_memcpy(void *dst, const void *src, size_t n);
char	**split(char *str, char *charset);
void    init(char *name);
int     print(char *str, int fd, int new);
char	*_strdup(const char *s1);
void    add_new_inst(char *o, void (*f)(stack_t **s, unsigned int l));
void    exic(void);
int     _strncmp(const char *s1, const char *s2, size_t n);
void    pall(stack_t **stack, unsigned int line_number);
int     _atoi(char *s);
char	*_itoa(int n);
void    free_inst(char **str);
void    free_all(void);
void    push(stack_t **stack, unsigned int line_number);
void    mexit(void);
void    pint(stack_t **stack, unsigned int line_number);
void    nop(stack_t **stack, unsigned int line_number);
void    pop(stack_t **stack, unsigned int line_number);
size_t  stack_len(const stack_t *h);
void    swap(stack_t **stack, unsigned int line_number);
void    add(stack_t **stack, unsigned int line_number);
void    sub(stack_t **stack, unsigned int line_number);
void    divv(stack_t **stack, unsigned int line_number);
void    mul(stack_t **stack, unsigned int line_number);
void    mod(stack_t **stack, unsigned int line_number);
void    pchar(stack_t **stack, unsigned int line_number);
void    pstr(stack_t **stack, unsigned int line_number);
void	rotl(stack_t **stack, unsigned int line_number);
void	rotr(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void	stack(stack_t **stack, unsigned int line_number);
void	queue(stack_t **stack, unsigned int line_number);
#endif
