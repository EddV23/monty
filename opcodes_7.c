#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current->next->n -= current->n;
	pop(stack, line_number);
}
