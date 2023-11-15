#include "monty.h"
#include <ctype.h>

/**
 * is_number - Checks if a string is a valid number.
 * @str: String to check.
 * Return: 1 if it's a number, 0 otherwise.
 */
int is_number(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0);
	}

	while (*str)
	{
		if (!isdigit(*str) && *str != '-')
		{
			return (0);
		}
		str++;
	}

	return (1);
}

/**
 * add_queue - Adds a node to the end of a queue.
 * @stack: Pointer to the top of the stack.
 * @value: Value to be added.
 */
void add_queue(stack_t **stack, int value)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		temp = *stack;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
}

/**
 * add_stack - Adds a node to the top of a stack.
 * @stack: Pointer to the top of the stack.
 * @value: Value to be added.
 */
void add_stack(stack_t **stack, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = *stack;
	*stack = new_node;
}
