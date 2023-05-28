#include "monty.h"
/**
 * addStackHeader - Adds a new node to head
 * @head: head pointer
 * @n: stack-n
 *
 * Return: A pointer to the new head of the list
 */
stack_t *addStackHeader(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		freeAndExit (head);
	}
	new_node->n = n;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		*head = new_node;
		return (*head);
	}
	(*head)->prev = new_node;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
	return (*head);
}
/**
 * deleteStackHead - Deletes header
 * @head: A pointer to the head of the list
 *
 * Return: Void
 */
void deleteStackHead(stack_t **head)
{
	stack_t *temp_node;

	if (*head == NULL)
	{
		printf("Error");
		freeAndExit(head);
	}
	temp_node = *head;
	if (temp_node->next != NULL)
	{
		*head = temp_node->next;
		(*head)->prev = NULL;
		free(temp_node);
	}
	if (temp_node->next == NULL)
	{
		free(temp_node);
		*head = NULL;
	}
}
/**
 * printStackHead - Prints the head node
 * @head: head pointer
 * @n: stack-n
 *
 * Return: void
 */
void printStackHead(stack_t **head, int n)
{
    stack_t *current = *head;

    if (current == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", n);
        freeAndExit(head);
    }
    printf("%d\n", current->n);
}
/**
 * printAll2 - Prints all elements in a doubly linked list
 * @head:  head pointer
 *
 * Return: void
 */
void printAll2(stack_t **head)
{
    stack_t *current = *head;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
*freeAllList - frees whole list
* @head:  head pointer
*
*Return: void
*/
void freeAllList(stack_t *head)
{
	stack_t *temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}
