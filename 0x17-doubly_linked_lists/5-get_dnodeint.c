#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: beginning of the list
 * @index: to return
 * Return: the nth node or NULL if it doesnt exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temp = head;
	unsigned int i = 0;

	while (temp)
	{
		if (i == index)
			return (temp);
		temp = temp->next;
		i++;
	}

	return (NULL);
}
