/**
  * _strcmp -  compares two strings.
  * @s1: pointer to string
  * @s2: pointe to string
  * Return: integer
  */

int _strcmp(char *s1, char *s2)
{
	int i;

	if (s1 != s2)
	{
		for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
		{
			if (s1[i] == s2[i])
			{
				if ((s1[i] == '\0') && (s2[i] == '\0'))
				{
					return (0);
				}

				continue;
			}
			else if (s1[i] > s2[i])
			{
				return (15);
			}
			else
			{
				return (-15);
			}
		}
	}
	return (0);
}
