#include "lists.h"

/**
 * is_palindrome - declare pointers to check for linked list palindrome
 * @head: pointer to pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int list_size = 0;
	int *array = NULL;
	int x = 0;

	if (!head || !*head)
		return (1);

	/* Count number of nodes in list */
	while (current)
	{
		current = current->next;
		list_size++;
	}

	/* Create array of size list_size */
	array = malloc(sizeof(int) * list_size);
	if (array == NULL)
		return (0);

	/* Set current back to head of list */
	current = *head;
	/* Fill array with values from list */
	while (current)
	{
		array[x] = current->n;
		current = current->next;
		x++;
	}

	/* Set current back to head of list */
	current = *head;
	/* Check if palindrome */
	for (x = 0; x < list_size / 2; x++)
	{
		if (array[x] != array[list_size - x - 1])
			return (0);
	}

	return (1);
}
