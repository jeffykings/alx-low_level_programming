#include "main.h"

/**
  * _islower - check for lowercase letters
  * Return: integer value
  * @c: its an integer parameter
  */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
