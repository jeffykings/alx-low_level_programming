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

	while (temp && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	if ((i == idx - 1) && temp->next)
	{
		newnode = malloc(sizeof(dlistint_t));
		if (newnode == NULL)
			return (NULL);
		newnode->n = n;
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next->prev = newnode;
		temp->next = newnode;
		return (newnode);
	}
	return (NULL);
}
