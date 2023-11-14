#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *temp;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (current->next != NULL)
			current = current->next;

		temp = current->prev;
		current->prev = NULL;
		temp->next = NULL;

		current->next = *stack;
		(*stack)->prev = current;
		*stack = current;
	}
}
