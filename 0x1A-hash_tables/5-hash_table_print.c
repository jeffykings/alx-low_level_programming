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

	int first = 1;

	printf("{");

	for (i = 0; ht && i < ht->size; i++)
	{
		temp = ht->array[i];

		while (temp)
		{
			if (!first)
				printf(", ");

			printf("\'%s\': \'%s\'",temp->key, temp->value);
			first = 0;

			temp = temp->next;
		}
	}
	printf("}\n");
}
