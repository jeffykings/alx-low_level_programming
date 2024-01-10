#include "lists.h"

/**
 * add_dnodeint_end - adds newnode at the end of the list
 * @head: beginning of the head
 * @n: element to be added
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp, *newnode;

	temp = *head;

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;

	while (temp && temp->next)
		temp = temp->next;
	if (*head)
	{
		newnode->prev = temp;
		temp->next = newnode;
	}
	else
	{
		newnode->prev = NULL;
		*head = newnode;
	}
	newnode->next = NULL;

	return (newnode);
}
