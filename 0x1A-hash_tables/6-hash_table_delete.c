#include "hash_tables.h"

/**
 * hash_table_delete -  a function that deletes a hash table.
 *
 * @ht:   is the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *temp;
	hash_node_t *temo2;
	unsigned long int i;

	for (i = 0; ht && i < ht->size; i++)
	{
		temp = ht->array[i];

		while (temp)
		{
			temp2 = temp;
			temp = temp->next;
			free(tmep2->key);
			free(temp2->value);
			free(temp2);
		}
	}

	free(ht->array);
	free(ht);
}
