#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *temp;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;

		while (current->next != NULL)
			current = current->next;

		current->next = temp;
		temp->prev = current;
		temp->next = NULL;
	}
}
