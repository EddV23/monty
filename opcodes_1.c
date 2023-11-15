#include "monty.h"

/*
 *can remove comments around int mode below but make sure
 *to comment out this mode definition in the file monty.c
 */
int mode = STACK_MODE;

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *token;
	int value;

	token = strtok(NULL, " \n");
	if (token == NULL || !is_number(token))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(token);

	if (mode == QUEUE_MODE)
		add_queue(stack, value);
	else
		add_stack(stack, value);
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
