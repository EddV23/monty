#include "monty.h"

myglobe_t global;

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1;
	stack_t *tmp2;
	int sum = 0;

	if (*stack && (*stack)->next)
	{
		tmp2 = (*stack)->next;
		sum = (*stack)->n + tmp2->n;
		tmp1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(tmp1);
		(*stack)->n = sum;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
