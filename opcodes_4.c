#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
