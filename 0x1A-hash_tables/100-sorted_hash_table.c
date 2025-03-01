#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: the size of the array
 *
 * Return: if success a pointer to the newly created hash table else NULL
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;

	shash_table_t *table = malloc(sizeof(shash_table_t));

	if (table == NULL)
	{
		return (NULL);
	}
	table->size = size;

	table->array = malloc(size * sizeof(hash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		table->array[i] = NULL;
	}

	table->shead = NULL;
	table->stail = NULL;

	return (table);
}

/**
 * shash_table_set - a function that adds an element to the hash table
 * in a sorted way.
 *
 * @ht: is the hash table you want to add or update the key/value to
 * @key:  is the key. key can not be an empty string
 * @value: is the value associated with the key. value must be
 * duplicated. value can be an empty string
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *hash_element;
	unsigned long int idx;

	if (ht == NULL)
		return (0);

	if (key == NULL || strcmp(key, "") == 0)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	hash_element = screate_hash_table_element(key, value);

	if (hash_element == NULL)
		return (0);

	if (ht->array[idx] == NULL)
		ht->array[idx] = hash_element;
	else
		shandle_collision(ht, hash_element, key, idx);

	if (ht->shead == NULL)
	{
		ht->shead = hash_element;
		ht->stail = hash_element;
	} else if (strcmp(ht->shead->key, key) > 0)
	{
		hash_element->snext = ht->shead;
		ht->shead->sprev = hash_element;
		ht->shead = hash_element;
	} else
	{
		add_sorted_tail_mid(ht, hash_element,  key);
	}
	return (1);
}

/**
 * add_sorted_tail_mid - for add values at the middle and end of
 * the sorted linked list
 *
 * @ht: the hash table
 * @hash_element: items in the hast table
 * @key: the key to be added
 */
void add_sorted_tail_mid(shash_table_t *ht,
		shash_node_t *hash_element, const char *key)
{
	shash_node_t *temp;

	temp = ht->shead;
	while (temp->snext != NULL && strcmp(temp->snext->key, key) < 0)
		temp = temp->snext;
	if (temp->snext == NULL && strcmp(temp->key, key) < 0)
	{
		ht->stail = hash_element;
		temp->snext = hash_element;
		hash_element->sprev = temp;
	}
	else
	{
		hash_element->sprev = temp->sprev;
		ht->shead = hash_element;
		hash_element->snext = temp;
		temp->sprev = hash_element;
	}
}

/**
 * screate_hash_table_element - create the items in the table
 *
 * @key: is the key. key can not be an empty string
 * @value: is the value associated with the key. value must be
 * duplicated. value can be an empty string
 *
 * Return: if successful the address of the created node else NULL
 */
shash_node_t *screate_hash_table_element(const char *key, const char *value)
{
	shash_node_t *newnode = malloc(sizeof(shash_node_t));

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
	newnode->sprev = NULL;
	newnode->snext = NULL;
	return (newnode);
}

/**
 * _sfree_item - free items inside a node
 *
 * @node: node to be freed
 */
void _sfree_item(shash_node_t *node)
{
	if (node == NULL)
		return;

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
void shandle_collision(shash_table_t *ht, shash_node_t *hash_element,
		const char *key, unsigned long int idx)
{
	shash_node_t *prev;
	shash_node_t *temp;

	temp = ht->array[idx];
	prev = NULL;

	while (temp && temp->next != NULL)
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

			_sfree_item(temp);
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
		_sfree_item(temp);
	} else
	{
		hash_element->next = ht->array[idx];
		ht->array[idx] = hash_element;
	}
}

/**
 * shash_table_get - a function that retrieves a value associated with a key
 *
 * @ht:   is the hash table you want to look into
 * @key: is the key you are looking for
 *
 * Return:  value associated with the element, or NULL
 * if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *temp;
	unsigned long int idx;

	if (ht == NULL)
		return (NULL);

	idx = key_index((const unsigned char *) key, ht->size);

	if (ht->array[idx] != NULL)
	{
		temp = ht->array[idx];
		while  (temp && temp->next)
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

/**
 * shash_table_print -  Should print the hash table using the
 * sorted linked list
 *
 * @ht: is the hash table
 */
void shash_table_print(const shash_table_t *ht)
{

	shash_node_t *temp;

	if (ht == NULL)
		return;

	printf("{");
	temp = ht->shead;

	while (temp)
	{
		printf("\'%s\': \'%s\'", temp->key, temp->value);
		temp = temp->snext;

		if (temp != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev -  Should print the hash table using
 * the sorted linked list in rev
 *
 * @ht: is the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{

	shash_node_t *temp;

	if (ht == NULL)
		return;

	printf("{");
	temp = ht->stail;

	while (temp)
	{
		printf("\'%s\': \'%s\'", temp->key, temp->value);
		temp = temp->sprev;

		if (temp != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete -  a function that deletes a hash table.
 *
 * @ht:   is the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *temp, *temp2;

	temp = ht->shead;

	while (temp)
	{
		temp2 = temp->snext;
		free(temp->key);
		free(temp->value);
		free(temp);
		temp = temp2;
	}

	free(ht->array);
	free(ht);
}
