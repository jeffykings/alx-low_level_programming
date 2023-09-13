#include "main.h"

/**
  * main- entry point of the ptogram and calls the print_alpabet function
  * Return: 0 is always success
  */

int main(void)
{

	print_alphabet();

	return (0);
}

/**
  * print_alphabet- prints all lower case letters
  * Return: doesnt return any value
  */

void print_alphabet(void)
{
	int i = 0;

	while (i <= 122)
	{
		_putchar(i);
		i++;
	}

	_putchar('\n');
}
