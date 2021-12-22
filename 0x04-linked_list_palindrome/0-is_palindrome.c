#include "lists.h"

/**
 * is_palindrome - declare pointers to check for linked list palindrome
 * @head: pointer to pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	if (!head || !*head)
		return (1);

	return (check_palindrome_rec(head, *head));
}

/**
 * check_palindrome_rec - recursive check if linked list is palindrome
 * @left: pointer starts at head of list, ends at middle of list
 * @right: pointer starts at second in list, ends at last node
 * Return: 1 if palindrome, 0 if not
 */
int check_palindrome_rec(listint_t **left, listint_t *right)
{
	/* Base case - end of list */
	if (right == NULL)
		return (1);

	/* When uncurls, left at start and right at end */
	if (check_palindrome_rec(left, right->next) == 0)
		return (0);

	/* Check if left and right nodes are equal */
	if ((*left)->n != right->n)
		return (0);

	/* Move left pointer to next node to keep up with uncurling */
	*left = (*left)->next;

	return (1);
}
