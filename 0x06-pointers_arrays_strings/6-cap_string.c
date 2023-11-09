/**
  * cap_string - capitalizes all words of a string
  * @str: pointer to the string
  * Return: pointer to character
  */

char *cap_string(char *str)
{
	int i, j;

	char array[] = {' ', '\t', '\v', '\n', ',', ';', '.', '!', '?', '"',
		'(', ')', '{', '}', '\0'};

	for  (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0)
		{
			continue;
		}
		else if (str[0] >= 'a' && str[0] <= 'z')
		{
			str[0] = str[0] - 32;
		}
		else
		{
			for (j = 0; array[j] != '\0'; j++)
			{
				if ((str[i - 1] == array[j]) && (str[i] >= 97 && str[i] <= 122))
				{
					str[i] = str[i] - 32;
					break;
				}
			}
		}
	}
	return (str);
}
