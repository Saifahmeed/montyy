#include "monty.h"
/**
 * freeAndExit - Frees list then exit program
 * @head: head pointer
 *
 * Return: void
 */
void freeAndExit(stack_t **head)
{
    if (line)
        free(line);
    if (file)
        fclose(file);
    if (*head != NULL)
        freeAllList(*head);
    exit(EXIT_FAILURE);
}
