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

	if (key == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	hash_element = create_hash_table_element(key, value);

	if (ht->array[idx] == NULL)
		ht->array[idx] = hash_element;
	else
	{
		hash_element->next = ht->array[idx];
		ht->array[idx] = hash_element;
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
