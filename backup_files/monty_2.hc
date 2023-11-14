#include "monty.h"

/* Default mode is stack */
int mode = STACK_MODE;

void monty(const char *file_path) {
	FILE *file = fopen(file_path, "r");
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	/*Read lines from the file*/
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		/*Tokenize the line to extract opcode and arguments*/
		char *token = strtok(line, " \t\n");
		if (token != NULL)
		{
			/*Find the corresponding opcode function*/
			instruction_t *instruction = get_instruction(token);
			if (instruction != NULL)
			{
				/*Call opcode func with stack & line number*/
				instruction->f(&stack, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s
\n", line_number, token);
				exit(EXIT_FAILURE);
			}
		}
	}

	/*Free allocated memory and close the file*/
	free(line);
	fclose(file);
	free_stack(stack);
}

/**
 * main - Entry point
 * @argc - Argument count
 * @argv - Argument variable
 *
 * Return - Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	FILE *file;

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

	monty(file);

	fclose(file);
	return (EXIT_SUCCESS);
}
