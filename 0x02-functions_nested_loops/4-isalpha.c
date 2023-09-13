#include "main.h"

/**
  * _isalpha - this function checks for alphabetic characters
  * @c : interger parameter
  * Return: returns 1 if the c is lowercase or uppercase and 0 otherwi
  */

int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);

	else
		return (0);
}
