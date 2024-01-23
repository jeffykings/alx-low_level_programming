#include <unistd.h>

/**
  * _putchar - this prints a character
  * @c: this takes in a single character arguement
  * Return: int on successful character printing
  */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
