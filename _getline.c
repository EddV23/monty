#include <stdio.h>
#include <stdlib.h>

/* Define ssize_t if not available (e.g., on Windows) */
#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
typedef long ssize_t;
#endif

/**
 * _getline - Custom getline function to read a line from a file stream.
 * @lineptr: Pointer to the buffer where the line is stored.
 * @n: Pointer to the size of the buffer.
 * @stream: File stream to read from.
 *
 * Return: Number of characters read, -1 on failure or end of file.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = 1024;
	size_t pos = 0;
	int ch;

	*lineptr = (char *)malloc(bufsize);
	if (*lineptr == NULL)
	{
		perror("_getline");
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(stream)) != EOF && ch != '\n')
	{
		if (pos >= bufsize - 1)
		{
			bufsize *= 2;
			*lineptr = realloc(*lineptr, bufsize);
			if (*lineptr == NULL)
			{
				perror("_getline");
				exit(EXIT_FAILURE);
			}
		}

		(*lineptr)[pos++] = ch;
	}

	if (ch == EOF && pos == 0)
	{
		free(*lineptr);
		*lineptr = NULL;
		return (-1);
	}

	(*lineptr)[pos] = '\0';

	*lineptr = realloc(*lineptr, pos + 1);
	if (*lineptr == NULL)
	{
		perror("_getline");
		exit(EXIT_FAILURE);
	}

	*n = pos;

	return (pos);
}
