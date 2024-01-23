/**
  * _strchr - locates a character in a string.
  * @s: pointer string. string to be checked
  * @c: character looking for.
  * Return: pointer to string
  */

char *_strchr(char *s, char c)
{
	while (1)
	{
		s++; /* moves pointer from one point to another*/

		if (*s == c)
		{
			return (s);
		}
	}

	return ("NULL");
}
