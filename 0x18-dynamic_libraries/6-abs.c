#include "main.h"

/**
  * _abs - computes the absolute value of an integer
  * @n : takes an inpute of integer
  * Return: it returns a postive integeter
  */

int _abs(int n)
{
	if (n < 0)
	{
/**		unsigned int p;

		p = n * -1; 
 		
 		return (p);
 */

		return ((n * -1));
	}

	else
		return (n);
}
