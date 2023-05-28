#include "monty.h"
/**
*mread_file - opens file and reads it
*@filename: file name
*@stack: pointer to pointer of stack
*
*Return: void
*/
char *line = NULL;
FILE *file;
void mread_file(char *filename, stack_t **stack)
{
	size_t len = 0;
	int n_read;
	int line_count = 1;
	char *command;
	instruct_func s;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		freeAndExit(stack);
	}
	while ((n_read = newGetLine(&line, &len, file)) != -1)
	{
		command = parseLine(line);

		if (command == NULL || command[0] == '#')
		{
			line_count++;
			continue;
		}
		s = getRightFunction(command);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, command);
			freeAndExit(stack);
		}
		s(stack, line_count);
		line_count++;
	}
	free(line);
	if ((fclose(file)) == -1)
		exit(-1);
}
/**
*getRightFunction - selects right function
*@str: opcode
*
*Return: function pointer
*/
instruct_func getRightFunction(char *str)
{
	int i;

	instruction_t instruct[] = {
			{"push", pushNode},
			{"pint", pintNode},
			{"add", addToStack},
			{"swap", swapNodes},
			{"pop", popNode},
			{"pall", printAllNodes},
			{"nop", doNothing},
			{"sub", subtract},
			{"mul", multiply},
			{"div", divideStack},
			{"mod", getMod},
			{"rotl", moveFirstToLast},
			{"pchar", myPutChar},
			{NULL, NULL}
	};

	i = 0;

	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}
	return (instruct[i].f);
}
/**
*parseLine - tokenize line
*@str: line
*
*Return: a word, the opcode command
*/
char *parseLine(char *str)
{
	char *opcode;

	opcode = strtok(str, "\n ");
	if (opcode == NULL)
		return (NULL);
	return (opcode);
}

#define BUFFER_SIZE 1024
/**
*newGetLine - getline()
*@lptr: pointer to line
*@n: number of chars
*@stream: file or src
*
*Return: number of chars
*/
size_t newGetLine(char **lptr, size_t *n, FILE *stream)
{
	size_t ps;
	int c;

	if (*lptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lptr = (char *)malloc(*n);
	}
	if (*lptr == NULL)
	{
		return (-1);
	}
	ps = 0;

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (ps >= *n - 1)
		{
			char *new_lptr;
			*n += BUFFER_SIZE;
			new_lptr = (char *)realloc(*lptr, *n);

			if (new_lptr == NULL)
			{
				free(*lptr);
				return (-1);
			}
			*lptr = new_lptr;
		}
		(*lptr)[ps++] = (char)c;
	}
	if (c == EOF && ps == 0)
	{
		return (-1);
	}
	(*lptr)[ps] = '\0';
	return (ps);
}
/**
*isANumber - checks for numbers
*@str: string to test
*
*Return: 1 on sucess or -1 on failure
*/
int isANumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
