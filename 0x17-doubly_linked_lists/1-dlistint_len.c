#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t
 * list.
 * @h: head of the list
 * Return: the number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *temp = h;
	size_t n = 0;

	while (temp)
	{
		n++;
		temp = temp->next;
	}

	return (n);
}
