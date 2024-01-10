#include "lists.h"

/**
 * add_dnodeint - adds new node at the beginning of dlistint_t list
 * @head: beginning of the list
 * @n: number to be added
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newnode;

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
		return (NULL);
	if (*head != NULL)
		(*head)->prev = newnode;
	newnode->n = n;
	newnode->next = *head;
	newnode->prev = NULL;
	*head = newnode;

	return (newnode);
}
