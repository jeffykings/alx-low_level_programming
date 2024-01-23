/**
  * _memset - fills memory with a constant byte.
  * @s: point to the string to be filled with constant value
  * @b: charactered used for the filling
  * @n: integer. number of positions to be filled
  */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(s + i) = b;
	}
	return (s);
}
