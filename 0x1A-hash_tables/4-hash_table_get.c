#include "hash_tables.h"

/**
 * hash_table_get - a function that retrieves a value associated with a key
 *
 * @ht:   is the hash table you want to look into
 * @key: is the key you are looking for
 *
 * Return:  value associated with the element, or NULL
 * if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *temp;
	unsigned long int idx;

	if (ht == NULL)
		return (NULL);

	idx = key_index((const unsigned char *) key, ht->size);

	if (ht->array[idx] != NULL)
	{
		temp = ht->array[idx];
		while  (temp->next)
		{
			if (strcmp(temp->key, key) == 0)
				return (temp->value);

			temp = temp->next;
		}

		if (strcmp(temp->key, key) == 0)
			return (temp->value);
	}

	return (NULL);
}
