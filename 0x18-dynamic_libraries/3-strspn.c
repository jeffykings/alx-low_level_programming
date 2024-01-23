/**
  * _strspn - gets the length of a prefix substring.
  * @s: pointer to a string to be checked
  * @accept: the range of strings to be compared
  * Return: integer
  */

unsigned int _strspn(char *s, char *accept)
{
	int i, j, check, count;

	count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		check = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				count++;
				check = 1;
				break;
			}
		}

		if (check != 1)
		{
			return (count);
		}
	}

	return (count);
}
