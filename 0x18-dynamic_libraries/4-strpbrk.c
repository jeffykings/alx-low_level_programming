/**
  * _strpbrk -  searches a string for any of a set of bytes.
  * @s: A pointer to the null-terminated string to be examined'
  * @accept: A pointer to the null-terminated string containing the characters
  * to match.
  * Return:  returns a pointer to the first occurrence of any character from
  * the accept string in the str string. If no match is found, it returns NULL.
  */

char *_strpbrk(char *s, char *accept)
{
	int i;

	while (1)
	{
	for (i = 0; accept[i] != '\0'; i++)
	{
		if (accept[i] == *s)
		{
			return (s);
		}
	}

	s++;
	}

	return ("NULL");
}
