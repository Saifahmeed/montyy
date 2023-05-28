#include "monty.h"
/**
*getMod- mod 2 elements
*@stack: pointer to pointer of stack
*@lnum: number of line
*
*Return: void
*/
void getMod(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lnum);
		freeAndExit(stack);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lnum);
		freeAndExit(stack);
	}
	temp->next->n /= temp->n;
	*stack = temp;
	popNode(stack, lnum);
}
/**
*moveFirstToLast - move head to the last positon
*@stack: pointer to pointer of stack
*@lnum: number of line
*
*Return: void
*/
void moveFirstToLast(stack_t **stack, unsigned int lnum)
{
	(void)lnum;
	moveFirstToLastStack(stack);
}
/**
*myPutChar- prints first letter
*@stack: pointer to pointer of stack
*@lnum: number to be added
*
*Return: void
*/
void myPutChar(stack_t **stack, unsigned int lnum)
{
	printHeaderData(stack, lnum);
}
