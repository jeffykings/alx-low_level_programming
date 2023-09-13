#include "main.h"

/**
  * print_alphabet- prints all lower case letters
  * Return: doesnt return any value
  */

void print_alphabet(void)
{
	char i = 'a';

	while (i <= 'z')
	{
		_putchar(i);
		i++;
	}

	_putchar('\n');
}
