#include "monty.h"
/**
 * moveFirstToLastStack - Puts the first element of a stack at the end of the list
 * @head: head pointer
 *
 * Return: Pointer to the head of the list
 */
stack_t *moveFirstToLastStack(stack_t **head)
{
    stack_t *current, *last, *first;

    if (*head == NULL)
        freeAndExit(head);
    if ((*head)->next == NULL)
        return (*head);
    current = *head;
    last = current;
    first = current;

    while (last->next != NULL)
    {
        last = last->next;
    }
    *head = (*head)->next;
    first->next = NULL;
    last->next = first;
    first->prev = last;
    return (*head);
}
/**
 * printHeaderData - Prints the char at the head
 * @head: head pointer
 * @num: Line number
 *
 * Return: void
 */
void printHeaderData(stack_t **head, int num)
{
    stack_t *current = *head;
    int value;

    if (current == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
        freeAndExit(head);
    }
    value = current->n;
    if ((value < 65 || value > 91) && (value < 97 || value > 122))
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
        freeAndExit(head);
    }
    printf("%c\n", value);
}
