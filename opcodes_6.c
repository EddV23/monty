#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* This opcode does nothing */
}
