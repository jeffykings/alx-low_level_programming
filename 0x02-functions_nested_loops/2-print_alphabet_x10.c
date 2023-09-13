#include "main.h"

/**
  * print_alphabet_x10 - prints lower case of alphabet x10
  * Return: returns nothing
  */

void print_alphabet_x10(void)
{
	int i = 0;

	while (i < 10)
	{
		int letter = 'a';

		while (letter <= 'z')
		{
			_putchar(letter);

			letter++;
		}

		i++;

		_putchar('\n');
	}


}
