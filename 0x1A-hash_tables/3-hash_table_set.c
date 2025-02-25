 #include "hash_tables.h"

/**
 * hash_table_set - a function that adds an element to the hash table.
 *
 * @ht: is the hash table you want to add or update the key/value to
 * @key:  is the key. key can not be an empty string
 * @value: is the value associated with the key. value must be
 * duplicated. value can be an empty string
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *hash_element;
	unsigned long int idx;

	if (ht == NULL)
		return (0);

	if (key == NULL || strcmp(key, "") == 0)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	hash_element = create_hash_table_element(key, value);
	if (hash_element == NULL)
		return (0);
	if (ht->array[idx] == NULL)
		ht->array[idx] = hash_element;
	else
	{
		handle_collision(ht, hash_element, key, idx);
	}
	return (1);
}

/**
 * create_hash_table_element - create the items in the table
 *
 * @key: is the key. key can not be an empty string
 * @value: is the value associated with the key. value must be
 * duplicated. value can be an empty string
 *
 * Return: if successful the address of the created node else NULL
 */
hash_node_t *create_hash_table_element(const char *key, const char *value)
{
	hash_node_t *newnode = malloc(sizeof(hash_node_t));

	if (newnode == NULL)
	{
		return (NULL);
	}

	newnode->key = strdup(key);
	if (newnode->key == NULL)
	{
		free(newnode);
		return (NULL);
	}

	newnode->value = strdup(value);
	if (newnode->value == NULL)
	{
		free(newnode->key);
		free(newnode);
		return (NULL);
	}

	newnode->next = NULL;
	return (newnode);
}

/**
 * _free_item - free items inside a node
 *
 * @node: node to be freed
 */
void _free_item(hash_node_t *node)
{
	free(node->key);
	free(node->value);
	if (node->next != NULL)
		node->next = NULL;
	free(node);
}

/**
 * handle_collision - does what its name suggests
 *
 * @key: is the key. key can not be an empty string
 * @hash_element: the item we want to check for collision
 * @ht: hash table
 * @idx: the position we want to add value and key
 */
void handle_collision(hash_table_t *ht, hash_node_t *hash_element,
		const char *key, unsigned long int idx)
{
	hash_node_t *prev;
	hash_node_t *temp;

	temp = ht->array[idx];
	prev = NULL;

	while (temp->next != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			if (strcmp(temp->key, ht->array[idx]->key) == 0)
			{
				hash_element->next = temp->next;
				ht->array[idx] = hash_element;
			} else
			{
				hash_element->next = temp->next;
				prev->next =  hash_element;
			}

			_free_item(temp);
			return;
		}
		prev = temp;
		temp = temp->next;
	}

	if (strcmp(temp->key, key) == 0)
	{
		if (prev != NULL)
			prev->next = hash_element;
		else
			ht->array[idx] = hash_element;
		_free_item(temp);
	} else
	{
		hash_element->next = ht->array[idx];
		ht->array[idx] = hash_element;
	}
}
