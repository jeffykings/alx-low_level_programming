#include <unistd.h>

/**
  * _putchar - this prints a character
  * Return: int on successful character printing
  */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
