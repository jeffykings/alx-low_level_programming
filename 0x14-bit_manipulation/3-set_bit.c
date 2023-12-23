#include "main.h"

/**
  * set_bit -  sets the value of a bit to 1 at a given index.
  * @n: number whose index is required
  * @index: is the index, starting from 0 of the bit you want to get
  *
  * Return: the value of the bit at index index or -1 if an error occured
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	int *ptr;

	unsigned int i = 64;

	ptr = malloc(64 * sizeof(int));
	if (ptr == NULL)
	{
		printf("malloc error");
		return (-1);
	}
	if (index >= 64)
		return (-1);

	while (i > 0)
	{
		if (*n != 0)
		{
			ptr[i - 1] = *n % 2;
			*n = *n / 2;
		}
		else
			ptr[i - 1] = 0;
		i--;
	}
	for (i = 0; i <= 63 ; i++)
	{
		if (i == (63 - index))
		{
			ptr[i] = 1;
			*n = binary_to_dec(ptr, 64);
			free(ptr);
			return (1);
		}
	}
	free(ptr);

	return (-1);
}

/**
  * binary_to_dec - converts a binary number to an unsigned int.
  * @b: pointer to the binary to be converted
  * @size: the size it will occupy in memmory
  * Return: the converted number, else 0 if there is one or more chars in the
  * string b that is not 0 or 1 or b is NULLi
  */
unsigned int binary_to_dec(const int *b, unsigned int size)
{
	unsigned int count;

	unsigned int sum = 0, i = 0;

	size--;
	count = size;

	while (size + 1 > i)
	{
		if (b[i] != 0)
			sum += b[i] << count;
		i++;
		count--;
	}
	return (sum);
}
