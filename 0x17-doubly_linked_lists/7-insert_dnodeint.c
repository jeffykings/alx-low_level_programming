#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: head of list
 * @idx: list index
 * @n: number to be addedi
 * Return:  the address of the new node, or NULL if it failed
 * if it is not possible to add the new node at index idx, do not add the
 * new node and return NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *newnode, *temp = *h;
	unsigned int i = 0;

	if (idx == 0)
	{
		return (add_dnodeint(h, n));
	}

	while (temp && i < idx)
	{
		temp = temp->next;
		i++;
	}

	if (i == idx && temp)
	{
		newnode = malloc(sizeof(dlistint_t));
		if (newnode == NULL)
			return (NULL);
		newnode->n = n;
		newnode->next = temp;
		newnode->prev = temp->prev;
		temp->prev->next = newnode;
		temp->prev = newnode;
		return (newnode);
	}
	if (i == idx && temp == NULL)
		return (add_dnodeint_end(h, n));
	return (NULL);
}
