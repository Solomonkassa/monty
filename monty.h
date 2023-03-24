#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#define Buffsize 30

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
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
 * struct glob_var - golbal variables
 * @file: file name
 * @buff: Getline buffer
 * @tmp: Getline counter
 * @dict: instruction dictionary
 * @head: pointer to list
 * @line_number: Stores file current line
 * @MODE: Program configuration stack or queue
 */
typedef struct glob_var
{
	FILE *file;
	char *buff;
	size_t tmp;
	instruction_t *dict;
	stack_t *head;
	unsigned int line_number;
	int MODE;
} vars;


extern vars var;

/* ================================================================= */
/* man_file.c */
/* ================================================================= */
int start_vars(vars *var);
instruction_t *create_instru();
int call_funct(vars *var, char *opcode);
void free_all(void);
int _isdigit(char *string);

/* ================================================================= */
/* op_funct.c */
/* ================================================================= */
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/* ================================================================= */
/* op_funct_2.c */
/* ================================================================= */
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);

/* ================================================================= */
/* op_funct_3.c */
/* ================================================================= */
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/* ================================================================= */
/* op_funct_4.c */
/* ================================================================= */
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);


#endif
