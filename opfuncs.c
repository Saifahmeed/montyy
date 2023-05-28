#include "monty.h"
/**
*pushNode- adds to top of a stack
*@stack: pointer to pointer of stack
*@lnum: number to be added
*
*Return: void
*/
void pushNode(stack_t **stack, unsigned int lnum)
{
	char *arg;
	int value;

	arg = strtok(NULL, "\n ");
	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lnum);
		freeAndExit(stack);
	}
	if (isANumber(arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lnum);
		freeAndExit(stack);
	}
	value = atoi(arg);

	addStackHeader(stack, value);
}

/**
*pintNode- print first element in stack
*@stack: pointer to pointer of stack
*@lnum: number to be added
*
*Return: void
*/
void pintNode(stack_t **stack, unsigned int lnum)
{
	printStackHead(stack, lnum);
}

/**
*printAllNodes- prints all stack
*@stack: pointer to pointer of stack
*@lnum: number to be added to stack
*
*Return: void
*/
void printAllNodes(stack_t **stack, __attribute__((unused))unsigned int lnum)
{
	printAll2(stack);
}
/**
*popNode- deletes stack top
*@stack: pointer to pointer of stack
*@lnum: number to be added
*
*Return: void
*/

void popNode(stack_t **stack, unsigned int lnum)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lnum);
		freeAndExit(stack);
	}
	deleteStackHead(stack);
}
/**
*swapNodes- swaps 2 elements
*@stack: pointer to pointer of stack
*@lnum: number to be added
*
*Return: void
*/

void swapNodes(stack_t **stack, unsigned int lnum)
{
	int store;
	stack_t *temp;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lnum);
		freeAndExit(stack);
	}
	store = temp->n;
	temp->n = temp->next->n;
	temp->next->n = store;
}
