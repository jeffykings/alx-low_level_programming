#include "hash_tables.h"

/**
 * hash_table_print -  a function that prints a hash table
 * 
 * @ht: is the hash table
 */
void hash_table_print(const hash_table_t *ht)
{

	hash_node_t *temp;
	unsigned long int i;
	int n;

	printf("{");

	for (i = 0; ht && i < ht->size; i++)
	{
		temp = ht->array[i];
		n = 0;

		while (temp)
		{
			if ((n != i) && (i != ht->size - 1))
				printf(", ");

			printf("%s: %s",temp->key, temp->value);

			n = 1
			temp = temp->next;
		}
	}
	printf("}\n");
}
