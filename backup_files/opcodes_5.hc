#include "monty.h"

myglobe_t global;

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (global.mode == STACK_MODE)
	{
		current->next->n += current->n;
		pop(stack, line_number);
	}
	else if (global.mode == QUEUE_MODE)
	{
		current->n += current->next->n;
		pop(stack, line_number);
	}

	/*
	 *current->next->n += current->n;
	 *pop(stack, line_number);
	 */
}
