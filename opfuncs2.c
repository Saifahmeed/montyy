#include "monty.h"
/**
*doNothing- nothing to do
*@stack: pointer to pointer of stack
*@lnum: number to be added
*
*Return: void
*/
void doNothing(stack_t **stack, unsigned int lnum)
{
	(void)stack;
	(void)lnum;
}
/**
*addToStack- add element to stack
*@stack: pointer to pointer of stack
*@lnum: number to be added
*
*Return: void
*/

void addToStack(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lnum);
		freeAndExit(stack);
	}
	temp->next->n += temp->n;
	*stack = temp;
	popNode(stack, lnum);
}
/**
*subtract- make sub opration
*@stack: pointer to pointer of stack
*@lnum: number to be added
*
*Return: void
*/

void subtract(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lnum);
		freeAndExit(stack);
	}
	temp->next->n -= temp->n;
	*stack = temp;
	popNode(stack, lnum);
}
/**
*divideStack- div d 1st 2 elemnts of a stack stores d result in d 2nd elemnt, del 1st
*@stack: pointer to pointer of double linked list
*@lnum: number to be added to stack
*
*Return: void
*/
void divideStack(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lnum);
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
*multiply- multiply 2 elements
*@stack: pointer to pointer of stack
*@lnum: number to be added
*
*Return: void
*/

void multiply(stack_t **stack, unsigned int lnum)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lnum);
		freeAndExit(stack);
	}
	temp->next->n *= temp->n;
	*stack = temp;
	popNode(stack, lnum);
}
