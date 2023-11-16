#include "monty.h"
#include <stdio.h>

/*
 *can comment out int mode below but make sure to remove the
 *comments of the mode definition in the file opcode_1.c
 */
/*int mode = STACK_MODE;*/

void execute_instruction(char *instruction, stack_t **stack, unsigned int
			 line_number, myglobe_t *state);
void (*get_opcode_function(char *opcode))(stack_t **, unsigned int);
void free_stack(stack_t *stack);

/**
 * monty - Reads and interprets Monty bytecode from a file.
 * @file: Pointer to the Monty bytecode file.
 * @state: Pointer to the global variable mode
 */
void monty(FILE *file, myglobe_t *state)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	stack_t *stack = NULL;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		/* Ignore lines starting with # (comments) */
		if (line[0] == '#')
			continue;

		/* Parse and execute the instruction */
		execute_instruction(line, &stack, line_number, state);
	}

	free(line);
	free_stack(stack);
}

/**
 * execute_instruction - Parses and executes Monty bytecode instructions.
 * @instruction: Monty bytecode instruction.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the file.
 * @state: Pointer to the global variable mode
 */
void execute_instruction(char *instruction, stack_t **stack, unsigned int
			 line_number, myglobe_t *state)
{
	char *opcode;
	void (*func)(stack_t **, unsigned int);

	/*(void)state;*/

	opcode = strtok(instruction, " \t\n");

	if (opcode == NULL)
		/* Empty line */
		return;

	if (strcmp(opcode, "stack") == 0)
	{
		state->mode = STACK_MODE;
		return;
	}
	else if (strcmp(opcode, "queue") == 0)
	{
		state->mode = QUEUE_MODE;
		return;
	}
	func = get_opcode_function(opcode);

	if (func == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, opcode);
		exit(EXIT_FAILURE);
	}

	func(stack, line_number);
}

/**
 * get_opcode_function - Gets the function associated with a given opcode.
 * @opcode: Opcode to look up.
 * Return: Function pointer to the opcode's function, or NULL if not found.
 */
void (*get_opcode_function(char *opcode))(stack_t **, unsigned int)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul},
		{"mod", mod_op},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}};

	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
			return (opcodes[i].f);
		i++;
	}
	/* Opcode not found */
	return (NULL);
}

/**
 * free_stack - Frees the memory allocated for a stack.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument variable
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	FILE *file;
	myglobe_t state;

	state.mode = STACK_MODE;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	monty(file, &state);

	fclose(file);
	return (EXIT_SUCCESS);
}
