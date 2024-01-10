#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of a dlistint_u
 * linked list.
 * @head: beginning of the list
 * Return: sum 0f the list or ) if empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
