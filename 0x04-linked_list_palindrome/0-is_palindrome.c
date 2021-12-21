#include "lists.h"

/**
 * is_palindrome - declare pointers to check for linked list palindrome
 * @head: pointer to pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *mid = *head;
	listint_t *end = *head;
	listint_t *prev = NULL;
	listint_t *next = NULL;
	listint_t *tmp = NULL;

	if (!head || !*head)
		return (1);

	return (check_if_palindrome(mid, end, prev, next, tmp));
}


/**
 * check_if_palindrome - check for palindrome
 * @mid: pointer to pointer in middle of list
 * @end: pointer to pointer at end of list
 * @prev: pointer to node directly before mid
 * @next: pointer to node directly after mid
 * @tmp: pointer to temporary node that is used to check for palindrome
 * Return: 1 if palindrome, 0 if not
 */
int check_if_palindrome(listint_t *mid, listint_t *end,
	listint_t *prev, listint_t *next, listint_t *tmp)
{
	while (end && end->next)
	{
		/* Set prev pointer as previous node of mid */
		prev = mid;
		/* Send mid pointer to middle of the list */
		mid = mid->next;
		/* Send end pointer to end of the list */
		end = end->next->next;
	}

	/* If list has odd number of nodes, skip middle node */
	if (end)
		mid = mid->next;

	/* Reverse list from middle node */
	while (mid)
	{
		/* Save next node of mid */
		next = mid->next;
		/* Reverse next node of mid */
		mid->next = tmp;
		/* Save mid node */
		tmp = mid;
		/* Move mid pointer to next node */
		mid = next;
	}

	/* Compare the list with the reversed list */
	while (tmp)
	{
		/* If any node is not same, return 0 */
		if (tmp->n != prev->n)
			return (0);
		/* Move prev and tmp pointers to next nodes */
		tmp = tmp->next;
		prev = prev->next;
	}

	/* If all nodes are same, return 1 */
	return (1);
}
