#include "monty.h"
/**
*main - entry point
*@argmuntc: args count
*@argumentv: args list
*
*Return: 0 on success
*/
int main(int argmuntc, char *argumentv[])
{
	stack_t *stack;

	stack = NULL;
	if (argmuntc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		freeAndExit(&stack);
	}
	mread_file(argumentv[1], &stack);
	freeAllList(stack);
	return (0);
}
