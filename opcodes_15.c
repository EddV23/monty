#include "monty.h"

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.mode = STACK_MODE;
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.mode = QUEUE_MODE;
}
