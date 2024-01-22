#include "lists.h"

/**
 * delete_dnodeint_at_index -  deletes the node at index index of a dlistint_t
 * linked list.
 * @head: beginning of the list
 * @index: to be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int i;

	if (index == 0 && temp)
	{
		if (temp->next)
		{
			temp->next->prev = NULL;
			*head = temp->next;
		}
		else
			*head = NULL;
		free(temp);
		return (1);
	}
	for (i = 0; i < index && temp; i++)
		temp = temp->next;
	if (i == index && temp)
	{
		temp->prev->next = temp->next;
		if (temp->next != NULL)
		{
			temp->next->prev = temp->next;
		}
		free(temp);
		return (1);
	}
	return (-1);
}
