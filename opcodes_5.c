#include "monty.h"

myglobe_t global;

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1;
	stack_t *temp2;
	int sum = 0;

	if (*stack && (*stack)->next)
	{
		temp2 = (*stack)->next;
		sum = (*stack)->n + temp2->n;
		temp1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp1);
		(*stack)->n = sum;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		/*free(global.line);*/
		/*fclose(global.fil);*/
		/*free_stack(stack);*/
		exit(EXIT_FAILURE);
	}
}
