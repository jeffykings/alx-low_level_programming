#include "lists.h"

/**
  * get_nodeint_at_index -  returns the nth node of a listint_t linked list.
  * @head: the beginning of the list
  * @index: the index of the node
  *
  * Return: if the node does not exist NULL else the node
  */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *temp = head;

	while (temp)
	{

		if (count == index)
			return (temp);

		temp = temp->next;
		count++;
	}

	return (NULL);
}
